/*
 * =====================================================================================
 *
 *       Filename:  ltp_buddy.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/10/2012 10:51:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bean Lee
 *                  Feng Gao
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef LDP_BUDDY_H_
#define LDP_BUDDY_H_

#include "ltp_base_type.h"

typedef void * ldp_buddy_pool_h;


ldp_buddy_pool_h ldp_buddy_create(u32 min_order, u32 max_order);
void ldp_buddy_destroy(ldp_buddy_pool_h h);

void *ldp_buddy_malloc(ldp_buddy_pool_h h, u32 size);
void  ldp_buddy_free(ldp_buddy_pool_h h, void *p);
 
#endif

