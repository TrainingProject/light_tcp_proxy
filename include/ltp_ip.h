/*
 * =====================================================================================
 *
 *       Filename:  ltp_ip.h
 *
 *    Description:  The IP layer function header
 *
 *        Version:  1.0
 *        Created:  10/18/2012 10:11:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Feng Gao
 *          Email:  gfree.wind@gmail.com  
 *
 * =====================================================================================
 */
#ifndef LTP_IP_H_
#define LTP_IP_H_

#include <linux/ip.h>

extern int ltp_ip_handler(struct iphdr *iph);


#endif

