#
# Rule.make
# 	Define the common rules
#

LTP_LIB_DIR           := $(TOP_DIR)/lib
LTP_3RD_LIB_DIR       := $(TOP_DIR)/3rd/lib
LTP_BIN_DIR           := $(TOP_DIR)/bin
LTP_COMM_INC          := $(TOP_DIR)/include
LTP_3RD_INC           := $(TOP_DIR)/3rd/include
LTP_COMM_INC_FILES    := $(wildcard $(TOP_DIR)/include/*.h)

CC      := gcc
CFLAGS  += -Wall -Werror -fPIC -I$(LTP_COMM_INC) -I$(LTP_3RD_INC)
LFLAGS  += -L$(LTP_LIB_DIR)

ifeq ($(plat), )
$(error "make {plat=linux|...|}")
endif

ifeq ($(plat), linux)
CFLAGS += -DLTP_LINUX
endif

ifneq ($(release), yes)
CFLAGS += -g	
endif


# Common build rules
%.o: %.c $(LTP_COMM_INC_FILES)
	$(CC)  $(CFLAGS) -c $< -o $@


# Build dynamic libarary
ifdef LIB_TARGET
$(LIB_TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -o $(LIB_TARGET)
	@cp -f $(LIB_TARGET) $(LTP_LIB_DIR)/

install:
	@cp -f $(LIB_TARGET) $(prefix)/lib/
endif

# Buid executable bin
ifdef BIN_TARGET
$(BIN_TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -o $(BIN_TARGET)
	@cp -f $(BIN_TARGET) $(LTP_BIN_DIR)/

install:
	@cp -f $(BIN_TARGET) $(prefix)/bin/
endif

# Clean
clean:
	@rm -f $(LIB_TARGET) $(BIN_TARGET) *.o

