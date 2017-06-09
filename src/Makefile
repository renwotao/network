CC=gcc
CFLAGS=
INC=-I. 
OBJFILES := base/set_address.o \
	    base/tcp_client.o \
	    base/tcp_server.o
SRC := $(wildcard base/*.c) 
OBJ := $(SRC %.c=%.o)
TARGET := hb_client hb_server

.PHONY : all clean
all : $(TARGET)

hb_client : $(OBJFILES) hb_client.o
	$(CC) $(INC) $^ -o $@
hb_server : $(OBJFILES) hb_server.o
	$(CC) $(INC) $^ -o $@
%.o : %.c
	$(CC) -c  $(CFLAGS) $< -o $@

clean: 
	@rm -rf $(OBJFILES) hb_client.o hb_server.o
	@rm -rf $(TARGET)

