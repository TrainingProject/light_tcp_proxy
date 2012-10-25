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
#include <arpa/inet.h>
//#include <bits/sockaddr.h>
//#include <linux/in.h>
#include <linux/ip.h>

#include "ltp_debug.h"

int ltp_ip_handler(struct iphdr *iph)
{
    LTP_DEBUG_LOG("Receive one IPv4 packet\n");

    if (IPPROTO_TCP == iph->protocol) {
        LTP_DEBUG_LOG("It is a TCP packet\n");
        /* reverse ip & port */
        u32 addr = iph->saddr;
        addr = ntohl(addr);
        addr -= 1;
        addr = htonl(addr);
        iph->saddr = addr;
        
        //iph->saddr = iph->daddr;
        //iph->daddr = addr;

        
    }
    
    

    return 0;
}

