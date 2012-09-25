/*
 * =====================================================================================
 *
 *       Filename:  ltp_debug.h
 *
 *    Description:  Define the debug macro
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


#ifndef LTP_DEBUG_H_
#define LTP_DEBUG_H_

#include "ltp_config.h"

#ifdef LTP_DEBUG_PRINT
#include <stdlib.h>
#include <stdio.h>

#define LTP_debug_init()
#define LTP_debug_fini()

#define LTP_DEBUG_LOG(args...)		              fprintf(stderr, "[Debug] " args)
#define LTP_INFO_LOG(args...)                     fprintf(stderr, "[Info] "args)
#define LTP_NOTICE_LOG(args...)                   fprintf(stderr, "[Notice] " args)
#define LTP_WARNING_LOG(args...)                  fprintf(stderr, "[Warning] " args)
#define LTP_ERROR_LOG(args...)                    fprintf(stderr, "[Error] "args)
#define LTP_CRIT_LOG(args...)                     fprintf(stderr, "[Crit] " args)
#define LTP_ALERT_LOG(args...)                    fprintf(stderr, "[Alert] " args)
#define LTP_EMERG_LOG(args...)                    fprintf(stderr, "[Emerg] " args)

#define LTP_DEBUG_LOG_NO_PREFIX(args...)			fprintf(stderr, args)
#define LTP_INFO_LOG_NO_PREFIX(args...)        	    fprintf(stderr, args)
#define LTP_NOTICE_LOG_NO_PREFIX(args...)       	fprintf(stderr, args)
#define LTP_WARNING_LOG_NO_PREFIX(args...)      	fprintf(stderr, args)
#define LTP_ERROR_LOG_NO_PREFIX(args...)        	fprintf(stderr, args)
#define LTP_CRIT_LOG_NO_PREFIX(args...)         	fprintf(stderr, args)
#define LTP_ALERT_LOG_NO_PREFIX(args...)        	fprintf(stderr, args)
#define LTP_EMERG_LOG_NO_PREFIX(args...)        	fprintf(stderr, args)

#endif

#ifdef WR_IO_DEBUG_SYSLOG
#include <syslog.h>

static inline void LTP_debug_init(void)
{
    openlog("[Wrapper IO Lib]: ", LOG_CONS|LOG_NDELAY|LOG_PID, LOG_USER);
}

static inline void LTP_debug_fini(void)
{
    closelog();
}

#define LTP_DEBUG_LOG(args...)                    syslog(LOG_DEBUG, "[Debug] " args)
#define LTP_INFO_LOG(args...)                     syslog(LOG_INFO, "[Info] " args)
#define LTP_NOTICE_LOG(args...)                   syslog(LOG_NOTICE, "[Notice] " args)
#define LTP_WARNING_LOG(args...)                  syslog(LOG_WARNING, "[Warning] " args)
#define LTP_ERROR_LOG(args...)                    syslog(LOG_ERR, "[Error] " args)
#define LTP_CRIT_LOG(args...)                     syslog(LOG_CRIT, "[Crit]" args)
#define LTP_ALERT_LOG(args...)                    syslog(LOG_ALERT, "[Alert]" args)
#define LTP_EMERG_LOG(args...)                    syslog(LOG_EMERG, "[Emerg]" args)

#define LTP_DEBUG_LOG_NO_PREFIX(args...)       	syslog(LOG_DEBUG, args)
#define LTP_INFO_LOG_NO_PREFIX(args...)        	syslog(LOG_INFO, args)
#define LTP_NOTICE_LOG_NO_PREFIX(args...)      	syslog(LOG_NOTICE, args)
#define LTP_WARNING_LOG_NO_PREFIX(args...)     	syslog(LOG_WARNING, args)
#define LTP_ERROR_LOG_NO_PREFIX(args...)       	syslog(LOG_ERR, args)
#define LTP_CRIT_LOG_NO_PREFIX(args...)        	syslog(LOG_CRIT, args)
#define LTP_ALERT_LOG_NO_PREFIX(args...)       	syslog(LOG_ALERT, args)
#define LTP_EMERG_LOG_NO_PREFIX(args...)       	syslog(LOG_EMERG, args)
#endif

/*
Define the empty macro if no instance now
*/
#ifndef LTP_DEBUG_LOG
#define LTP_debug_init()
#define LTP_debug_fini()

#define LTP_DEBUG_LOG(args...)
#define LTP_INFO_LOG(args...)
#define LTP_NOTICE_LOG(args...)
#define LTP_WARNING_LOG(args...)
#define LTP_ERROR_LOG(args...)
#define LTP_CRIT_LOG(args...)
#define LTP_ALERT_LOG(args...)
#define LTP_EMERG_LOG(args...)

#define LTP_DEBUG_LOG_NO_PREFIX(args...)
#define LTP_INFO_LOG_NO_PREFIX(args...)
#define LTP_NOTICE_LOG_NO_PREFIX(args...)
#define LTP_WARNING_LOG_NO_PREFIX(args...)
#define LTP_ERROR_LOG_NO_PREFIX(args...)
#define LTP_CRIT_LOG_NO_PREFIX(args...)
#define LTP_ALERT_LOG_NO_PREFIX(args...)
#define LTP_EMERG_LOG_NO_PREFIX(args...)

#endif



/*
Generate warning when compile if condition is true
*/
#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))


#endif
