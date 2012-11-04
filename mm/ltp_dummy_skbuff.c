/*
 * =====================================================================================
 *
 *       Filename:  ltp_dummy_skbuff.c
 *
 *    Description:  The skbuff memory management
 *
 *        Version:  1.0
 *        Created:  10/25/2012 10:32:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Feng Gao
 *          Email:  gfree.wind@gmail.com  
 *
 * =====================================================================================
 */
#include <string.h>

#include "linux/skbuff.h"

#include "ltp_base_type.h"
#include "ltp_mem.h"
#include "ltp_debug.h"

/*
Now the skb mem size and data size are allocated together
But we could not assume it always is for ever.
*/
struct sk_buff *ltp_alloc_skbuff(u32 size)
{
    struct sk_buff *skb = ltp_alloc_mem(sizeof(*skb)+size);
    if (NULL == skb) {
        LTP_CRIT_LOG("ltp_alloc_mem failed\n");
        goto error1;
    }

    memset(skb, 0, sizeof(skb));
    skb->head = (u8*)(skb+1);
    skb->data = skb->head;
    skb_reset_tail_pointer(skb);
    skb->end = skb->tail + size;

    return skb;

error1:
    return NULL;
}

void ltp_free_skbuff(struct sk_buff* skb)
{
    ltp_free_mem(skb);
}

