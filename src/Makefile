.PHONY : all clean 
LIBSRC := $(wildcard base/*.c) 
LIBOBJ := $(LIBSRC:%.c=%.o)
SRC := $(wildcard *.c)
OBJ := $(SRC:%.c=%.o)

SRCFILES := $(wildcard base/*.c) $(wildcard *.c)
OBJFILES := $(SRCFILES:%.c=%.o)
LIB := libnet.a

all : hb_client hb_server 

$(OBJ):%.o: %.c
	gcc -c $< -o $@; echo $@
$(LIBOBJ):%.o:%.c
	gcc -c $< -o $@ 
$(LIB) : $(LIBOBJ) 
	ar crv $@ $^
hb_client : hb_client.o $(LIB)
	gcc $^ -o $@
hb_server : hb_server.o $(LIB)
	gcc $^ -o $@

clean :
	@rm -rf $(OBJ) $(LIBOBJ) $(LIB) hb_client hb_server
