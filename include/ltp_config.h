/*
 * =====================================================================================
 *
 *       Filename:  ltp_config.h
 *
 *    Description:  Define the config constant
 *
 *        Version:  1.0
 *        Created:  09/26/2012 01:02:14 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Feng Gao
 *          Email:  gfree.wind@gmail.com
 *
 * =====================================================================================
 */

#ifndef LTP_CONFIG_H_
#define LTP_CONFIG_H_

#include "ltp_base_type.h"

#ifdef __cplusplus
    extern "C" {
#endif

/*
OS type check
*/
#if !defined(LTP_LINUX) && !defined(LTP_DEBIAN) && !defined(LTP_AIX)
	#error "Please config one OS!"
#endif

/*
Debug switch
*/
#define LTP_DEBUG_PRINT
//#define LTP_DEBUG_SYSLOG


#define LTP_LITTLE_ENDIAN
//#define LTP_BIG_ENDIAN


#ifdef LTP_LITTLE_ENDIAN
#define __LITTLE_ENDIAN_BITFIELD
#endif

#ifdef LTP_BIG_ENDIAN
#endif


/*************************************** Function Define ****************************************************/
#define LTP_MAX_BUF_SIZE            2048



#ifdef __cplusplus
    }
#endif

#endif 
