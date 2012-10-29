#
# Author Feng Gao
#
#

TOP_DIR := ..

include $(TOP_DIR)/Makefile.def

CFLAGS  += -D__KERNEL__  
LFLAGS  += -shared -fPIC

LIB_TARGET := libltpnet.so
OBJS       := ltp_ip.o 


ifeq ($(plat), linux)
OBJS += 
endif

include $(TOP_DIR)/Rule.mak

