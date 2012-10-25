#
# Author Feng Gao
#
#

TOP_DIR := ..

include $(TOP_DIR)/Makefile.def

CFLAGS  += -D__KERNEL__ -nostdinc
LFLAGS  += -shared -fPIC -nostdinc

LIB_TARGET := libltpproxy.so
OBJS       := ltp_ip.o 


ifeq ($(plat), linux)
OBJS += 
endif

include $(TOP_DIR)/Rule.mak

