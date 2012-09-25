/*
 * =====================================================================================
 *
 *       Filename:  ltp_utils.h
 *
 *    Description:  Define some utils functions and macros
 *
 *        Version:  1.0
 *        Created:  09/25/2012 10:52:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Feng Gao
 *          Email:  gfree.wind@gmail.com
 *
 * =====================================================================================
 */

#ifndef LTP_UTILS_H_
#define LTP_UTILS_H_

#include "ltp_config.h"

#ifdef __cplusplus
    extern "C" {
#endif


#ifdef LTP_LINUX
#define likely(x)       __builtin_expect(!!(x),1)
#define unlikely(x)     __builtin_expect(!!(x),0)
#else 
#define likely(x)       (x)
#define unlikely(y)     (y)
#endif


#ifdef __cplusplus
    }
#endif

#endif
