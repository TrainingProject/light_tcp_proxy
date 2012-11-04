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
#include "ltp_errno.h"

/*
 *  Deliver IP Packets to the higher protocol layers.
 */
int ip_local_deliver(struct sk_buff *skb)
{
    /*
     *  Reassemble IP fragments.
     */

    if (ip_is_fragment(ip_hdr(skb))) {
        LTP_INFO_LOG("Ihe IP packet is fragmented\n");
        //if (ip_defrag(skb, IP_DEFRAG_LOCAL_DELIVER))
            return 0;
    }

    return LTP_OK;
}

