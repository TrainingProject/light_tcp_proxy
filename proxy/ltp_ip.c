/*
 * =====================================================================================
 *
 *       Filename:  ltp_ip.c
 *
 *    Description:  Implement the IP layer
 *
 *        Version:  1.0
 *        Created:  10/18/2012 10:10:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Feng Gao
 *          Email:  gfree.wind@gmail.com
 *
 * =====================================================================================
 */
#include <linux/ip.h>

#include "ltp_debug.h"

int ltp_ip_handler(struct iphdr *iph)
{
    LTP_DEBUG_LOG("Receive one IPv4 packet\n");
    

    return 0;
}

