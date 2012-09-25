/*
 * =====================================================================================
 *
 *       Filename:  ltp_base_type.h
 *
 *    Description:  Define the basic type
 *
 *        Version:  1.0
 *        Created:  09/26/2012 01:02:14 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Feng Gao
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef LTP_BASE_TYPE_H_
#define LTP_BASE_TYPE_H_

#ifdef __cplusplus
    extern "C" {
#endif


typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;


typedef u8             bool;


#ifndef TRUE
#define TRUE    1
#endif

#ifndef FALSE
#define FALSE   0
#endif


#ifdef __cplusplus
    }
#endif

#endif

