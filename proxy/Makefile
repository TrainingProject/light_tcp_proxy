#
# Author Feng Gao
#
#

TOP_DIR := ..

include $(TOP_DIR)/Makefile.def

CFLAGS  +=
LFLAGS  += -shared -fPIC

LIB_TARGET := libltpproxy.so
OBJS       := ltp_ip.o 


ifeq ($(plat), linux)
OBJS += 
endif

include $(TOP_DIR)/Rule.mak

