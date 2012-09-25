#
# Author Feng Gao
#
#

TOP_DIR := ..

include $(TOP_DIR)/Makefile.def

CFLAGS  += -I/$(prefix)/include
LFLAGS  +=

BIN_TARGET := ltp_main
OBJS       := ltp_main.o 


ifeq ($(plat), linux)
OBJS += 
endif

include $(TOP_DIR)/Rule.mak

