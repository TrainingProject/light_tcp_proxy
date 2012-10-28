/*
 * =====================================================================================
 *
 *       Filename:  ltp_assert.h
 *
 *    Description:  Implement the assert codes for running or compiling 
 *
 *        Version:  1.0
 *        Created:  10/28/2012 10:11:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Feng Gao
 *          Email:  gfree.wind@gmail.com  
 *
 * =====================================================================================
 */

#ifndef LTP_ASSERT_H_
#define LTP_ASSERT_H_

#define BUG_ON(c) do { if (c) {asm("int3"); }} while (0)


#endif

