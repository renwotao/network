.PHONY : all clean 
LIBSRC := $(wildcard base/*.c) 
LIBOBJ := $(LIBSRC:%.c=%.o)
SRC := $(wildcard *.c)
OBJ := $(SRC:%.c=%.o)
SRCFILES := $(wildcard base/*.c) $(wildcard *.c)
OBJFILES := $(SRCFILES:%.c=%.o)
LIB := libnet.a
TARGET := hb_client hb_server

all : $(TARGET) 

$(OBJFILES): %.o : %.c
	gcc -c $< -o $@
$(LIB) : $(LIBOBJ) 
	ar crv $@ $^
$(TARGET) : % : %.o $(LIB)
	gcc  $^ -o $@
clean :
	@rm -rf $(OBJ) $(LIBOBJ) $(LIB) $(TARGET) 
