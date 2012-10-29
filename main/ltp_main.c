/*
 * =====================================================================================
 *
 *       Filename:  ltp_main.c
 *
 *    Description:  The main daemon of LTP used to get the packet.
 *                  Now it is used to get packet from IPtable
 *
 *        Version:  1.0
 *        Created:  09/26/2012 12:56:11 AM
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

#include "ltp_debug.h"
#include "ltp_errno.h"
#include "ltp_utils.h"

#include "ltp_ip.h"
/***************************************************************************************/
static bool g_ltp_daemon_exit = FALSE;
/***************************************************************************************/
static void register_exit_signal_handler(void);
static void signal_exit_handler(int signum);
/***************************************************************************************/

int main(int argc, const char ** argv)
{
    static u8 buf[LTP_MAX_BUF_SIZE];
    struct ipq_handle *h = ipq_create_handle(0, NFPROTO_IPV4);

    if (!h) {
        LTP_ERROR_LOG("ipq_create_handle failed\n");
        goto error1;
    }

    int ret = ipq_set_mode(h, IPQ_COPY_PACKET, LTP_MAX_BUF_SIZE);
    if (-1 == ret) {
        LTP_ERROR_LOG("ipq_set_mode failed\n");
        goto error2;
    }

    register_exit_signal_handler();

    while (!g_ltp_daemon_exit) {
        ret = ipq_read(h, buf, LTP_MAX_BUF_SIZE, 0);
        if (ret < 0) {
            LTP_ERROR_LOG("ipq_read failed\n");
            goto error2;
        }
        ret = ipq_message_type(buf);
        if (likely(IPQM_PACKET == ret)) {
            LTP_DEBUG_LOG("Get one packet\n");
            ipq_packet_msg_t *pkt = ipq_get_packet(buf);
            if (likely(pkt)) {
            
                ret = ipq_set_verdict(h, pkt->packet_id, NF_DROP, pkt->data_len, pkt->payload);
                if (-1 == ret) {
                    LTP_ERROR_LOG("ipq_set_verdict failed\n");
                    goto error2;
                }
                
            }
            else {
                LTP_ERROR_LOG("ipq_get_packet failed\n");
                goto error2;
            }
        }
        else if (NLMSG_ERROR == ret) {
            LTP_ERROR_LOG("Recevie error msg(%d)\n", ipq_get_msgerr(buf));
            goto error2;
        }
        else {
            LTP_ERROR_LOG("Unknown type\n");
            goto error2;
        }
    }

    ipq_destroy_handle(h);

    return LTP_OK;

error2:
    ipq_destroy_handle(h);
    h = NULL;
error1:
    return LTP_ERR;
}



static void register_exit_signal_handler(void)
{
    signal(SIGQUIT, signal_exit_handler);
    signal(SIGTERM, signal_exit_handler);

    signal(SIGPIPE, SIG_IGN);
}

static void signal_exit_handler(int signum)
{
    g_ltp_daemon_exit = TRUE;
}


