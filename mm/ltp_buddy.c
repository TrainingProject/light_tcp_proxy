/*
 * =====================================================================================
 *
 *       Filename:  ltp_buddy.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/10/2012 10:50:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bean Lee <manuscola.bean@gmail.com>
 *					Feng Gao <gfree.wind@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */


#include<stdio.h>
#include<stdlib.h>

#include "ltp_assert.h"
#include "ltp_debug.h"
#include "ltp_buddy.h"

typedef struct ldp_buddy_pool {
    u32 min_order;
    u32 max_order;
    u64 size;
    u8  *bh;
    u8  *buffer;
} ldp_buddy_pool_t;

#define IS_POWER_OF_2(x)		(!((x)&((x)-1)))
#define LEFT_LEAF(index)		((index) * 2 + 1)
#define RIGHT_LEAF(index)		((index) * 2 + 2)
#define PARENT(index) 			(((index) + 1) / 2 - 1)

#define MAX(a,b) 				((a) > (b))?(a):(b)


static u32 next_order_of_2(u32 size)
{
    u32 order = 0;

	while ((1<<order) < size) {
		++order;
	}
    
    return order;
}

#define LDP_MAX_ORDER	64
ldp_buddy_pool_h ltp_buddy_create(u32 min_order, u32 max_order)
{
	if (max_order >= LDP_MAX_ORDER || min_order >= max_order) {
		LTP_ERROR_LOG("buddy_create, invalid param\n");
		goto err1;;
	}

	struct ldp_buddy_pool *p = malloc(sizeof(*p));
	if (NULL == p) {
		goto err1;
	}
	p->min_order = min_order;
	p->max_order = max_order;
	p->size = 1<<max_order;

    u32 bd_num = ((1<<(max_order-min_order))*2)-1;
	
    int ret = posix_memalign((void **)&(p->bh), 4096, bd_num);
    if (ret < 0) {
    	goto err2;
    }

	ret = posix_memalign((void **)&(p->buffer), 4096, p->size);
	if (ret < 0) {
		goto err3;
	}
    
	int i = 0;
	int current_order = max_order+1;
	for (i = 0; i < bd_num; ++i) {
		if (IS_POWER_OF_2(i+1))
			--current_order;
		p->bh[i] = current_order;
	}

	return p;

err3:
	free(p->bh);
err2:
	free(p);
err1:
	return NULL;
    
}

void ltp_buddy_destroy(ldp_buddy_pool_h* h)
{
	struct ldp_buddy_pool *p = (struct ldp_buddy_pool *)h;

    free(p->buffer);
    p->buffer = NULL;
    free(p->bh);
    p->bh = NULL;
    free(p);
    p = NULL;
}

void* ltp_buddy_malloc(ldp_buddy_pool_h* h, u32 size)
{
	struct ldp_buddy_pool *p = (struct ldp_buddy_pool *)h;
	u32 order = next_order_of_2(size);

	if (order < p->min_order) {
		order = p->min_order;
	}

	int index = 0;
	if (p->bh[0] < order) {
		LTP_ERROR_LOG("ltp_buddy_malloc, h(%p) no enough room\n", h);
		return NULL;
	}

	int current_order;
	for (current_order = p->max_order; current_order != order; --current_order) {
		if (p->bh[LEFT_LEAF(index)] >= order) {
			index = LEFT_LEAF(index);
		} else {
			index = RIGHT_LEAF(index);
		}
	}
	p->bh[index] = 0;

	void *ptr = p->buffer + (index+1)*(1<<order)-(p->size);
	while (index) {
		index = PARENT(index);
		p->bh[index] = MAX(p->bh[LEFT_LEAF(index)], p->bh[RIGHT_LEAF(index)]);
	}

	return ptr;
}

void ltp_buddy_free(ldp_buddy_pool_h* h, void* pointer)
{
	struct ldp_buddy_pool *p = (struct ldp_buddy_pool *)h;
    int offset = (u8*)pointer - p->buffer;
    int current_order = p->min_order;
    int current_index = 0;
    int found = 0;
    unsigned char left_order,right_order ;

	while (offset % (1<<current_order) == 0) {
		current_index = (1<<(p->max_order-current_order))-1+offset/(1<<current_order);
		if (p->bh[current_index] == 0) {
			found = 1;
			break;
		}
		++current_order;
	}

	p->bh[current_index] = current_order;
	while (current_index) {
		current_index = PARENT(current_index);
		++current_order;

		left_order = p->bh[LEFT_LEAF(current_index)];
		right_order = p->bh[RIGHT_LEAF(current_index)];

		if (left_order == (current_order-1) && right_order == (current_order-1)) {
			p->bh[current_index] = current_order;
		} else {
			p->bh[current_index] = MAX(left_order, right_order);
		}
	}	
}



