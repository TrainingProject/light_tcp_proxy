/*
 * =====================================================================================
 *
 *       Filename:  ltp_mem.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/31/2012 10:12:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bin Lee
 *                  Feng Gao
 *          email:  gfree.wind@gmail.com  
 *
 * =====================================================================================
 */
#ifndef LTP_MEM_H_
#define LTP_MEM_H_


extern void *ltp_alloc_mem(u32 size);
extern void ltp_free_mem(void *ptr);

#endif
