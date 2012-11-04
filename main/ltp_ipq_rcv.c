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
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>
#include <linux/in.h>
#include <linux/in6.h>
#include <linux/ip.h>
#include <linux/netfilter.h>
#include <libipq.h>

#include "linux/skbuff.h"

#include "ltp_errno.h"
#include "ltp_base_type.h"
#include "ltp_dummy_skbuff.h"
#include "ltp_debug.h"
#include "ltp_ip.h"

/*********************************************************************************************************/
static void init_skbuff(const struct ipq_packet_msg *ipq_msg, struct sk_buff *skb);
/*********************************************************************************************************/

int ltp_ipq_rcv(const struct ipq_packet_msg *ipq_msg)
{
    struct sk_buff *skb = ltp_alloc_skbuff(ipq_msg->data_len);
    if (NULL == skb) {
        LTP_CRIT_LOG("Fail to alloc skbuff\n");
        goto error1;
    }

    init_skbuff(ipq_msg, skb);

    if (LTP_OK != ip_local_deliver(skb)) {
        LTP_ERROR_LOG("ip_local_deliver failed\n");
        goto error1;
    }
    

    return LTP_OK;

error1:
    return LTP_ERR;
}


static void init_skbuff(const struct ipq_packet_msg *ipq_msg, struct sk_buff *skb)
{
    memcpy(skb->head, ipq_msg->payload, ipq_msg->data_len);
    skb->len = skb->data_len = ipq_msg->data_len;

    // Becasue the payload of ipq_msg l3 packet. so there is no mac header
    skb_set_mac_header(skb, ~0U);

    skb_set_network_header(skb, 0);

    struct iphdr *iph = (struct iphdr*)skb_network_header(skb);
    
    skb_set_transport_header(skb, iph->ihl<<2);
    
}
