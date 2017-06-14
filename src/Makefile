.PHONY : all clean 
LIBSRC := $(wildcard base/*.c) 
LIBOBJ := $(LIBSRC:%.c=%.o)
SRC := $(wildcard *.c)
OBJ := $(SRC:%.c=%.o)
LIB := libnet.a
TARGET := hb_client hb_server

all : $(TARGET) 

#.c.o:
#	gcc -c $< -o $@
$(LIB) : $(LIBOBJ) 
	ar crv $@ $^
$(TARGET) : % : %.o $(LIB)
	gcc  $^ -o $@
clean :
	@rm -rf $(OBJ) $(LIBOBJ) $(LIB) $(TARGET) 
