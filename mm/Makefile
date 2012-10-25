#
# Author Feng Gao
#
#

TOP_DIR := ..

include $(TOP_DIR)/Makefile.def

CFLAGS  += -D__KERNEL__ -nostdinc
LFLAGS  += -shared -fPIC -nostdinc

LIB_TARGET := libltpmm.so
OBJS       := ltp_dummy_skbuff.o 


ifeq ($(plat), linux)
OBJS += 
endif

include $(TOP_DIR)/Rule.mak

