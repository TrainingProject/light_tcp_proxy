#
# Author Feng Gao
#
#

TOP_DIR := ..

include $(TOP_DIR)/Makefile.def

CFLAGS  +=
LFLAGS  += -lipq -lltpnet

BIN_TARGET := ltp_main
OBJS       := ltp_main.o ltp_ipq_rcv.o


ifeq ($(plat), linux)
OBJS += 
endif

include $(TOP_DIR)/Rule.mak

