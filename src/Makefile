CC=gcc
CFLAGS=
INC=-I. -I ./base 
SRCFILES=$(wildcard base/*.c)
OBJFILES=$(SRCFILES:.c=.o)

all : hb_client hb_server

hb_client : $(OBJFILES) hb_client.o
	$(CC) $(OBJFILES) $^ -o $@
hb_server : $(OBJFILES) hb_server.o
	$(CC) $(OBJFILES) $^ -o $@
%.o : %.c
	$(CC) -c $(CFLAGS) $(INC) $< -o $@

.PHONY : clean

clean: 
	rm -rf $(OBJFILES) hb_client.o hb_server.o

