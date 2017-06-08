CC=gcc
CFLAGS=
INC=-I. -I ./base 
OBJFILES := base/set_address.o \
	    base/tcp_client.o
SRC := $(wildcard base/*.c)
OBJ := $(SRC %.c=%.o)

all : hb_client

%.o : %.c
	$(CC) -c  $(CFLAGS) $(INC) $< -o $@
hb_client : $(OBJFILES) hb_client.o
	$(CC) $(INC) $^ -o $@

.PHONY : all clean

clean: 
	@rm -rf $(OBJFILES) hb_client.o hb_server.o
	@rm -rf hb_client

