/*
 * =====================================================================================
 *
 *       Filename:  ltp_dummy_skbuff.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/28/2012 10:44:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Feng Gao
 *          Email:  gfree.wind@gmail.com  
 *
 * =====================================================================================
 */
#ifndef LTP_DUMMY_SKBUFF_H_
#define LTP_DUMMY_SKBUFF_H_

extern struct sk_buff *ltp_alloc_skbuff(u32 size);
extern void ltp_free_skbuff(struct sk_buff* skb);


#endif

