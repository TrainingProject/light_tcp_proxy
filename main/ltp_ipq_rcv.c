/*
 * =====================================================================================
 *
 *       Filename:  ltp_ipq_rcv.c
 *
 *    Description:  The receive routine which uses libipq
 *
 *        Version:  1.0
 *        Created:  10/29/2012 10:28:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Feng Gao
 *          Email:  gfree.wind@gmail.com  
 *
 * =====================================================================================
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>
#include <linux/in.h>
#include <linux/in6.h>
#include <linux/netfilter.h>
#include <libipq.h>

#include "ltp_errno.h"

int ltp_ipq_rcv(struct ipq_packet_msg *ipq_msg)
{
    

    return LTP_OK;
}
