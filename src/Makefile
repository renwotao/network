CC = gcc
INC = -I./framework/etcp.h
OBJ = hb_client.o hb_server.o

all: hb_client hb_server

hb_client: hb_client.o
    $(CC) -o hb_client hb_client.o

$(OBJ): hb_client.c hb_server.c
    $(CC) $(INC) $< -o $@

.PHONY clean
clean: 
    -rm -rf $(obj) $(all)

