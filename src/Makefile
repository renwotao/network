CC=gcc
CFLAGS=
INC=-I. 
HB_CLIENT_OBJ := base/set_address.o \
	    	base/tcp_client.o 
HB_SERVER_OBJ := base/set_address.o\
		base/tcp_server.o
SRC := $(wildcard base/*.c) 
OBJ := $(SRC %.c=%.o)
TARGET := hb_client hb_server

.PHONY : all clean
all : $(TARGET)

hb_client : $(HB_CLIENT_OBJ) hb_client.o
	$(CC) $(INC) $^ -o $@
hb_server : $(HB_SERVER_OBJ) hb_server.o
	$(CC) $(INC) $^ -o $@
%.o : %.c
	$(CC) -c  $(CFLAGS) $< -o $@

clean: 
	@rm -rf $(HB_CLIENT_OBJ) $(HB_SERVER_OBJ) hb_client.o hb_server.o
	@rm -rf $(TARGET)

