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


#ifdef LTP_LITTLE_ENDIAN
#define ltp_ntohs(x)        ((((u16)(x) & (u16)0x00FFU) << 8) | \
                             (((u16)(x) & (u16)0xFF00U) >> 8))
#define ltp_ntohl(x)        ((((u32)(x) & (u32)0x000000FFU) << 24) | \
                             (((u32)(x) & (u32)0x0000FF00U) << 8) | \
                             (((u32)(x) & (u32)0x00FF0000U) >> 8) | \
                             (((u32)(x) & (u32)0xFF000000U) >> 24))

#define ltp_htons(x)        ltp_ntohs(x)
#define ltp_htonl(x)        ltp_ntohl(x)


#endif

#ifdef __cplusplus
    }
#endif

#endif
