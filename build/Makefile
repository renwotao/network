objects = udpserver.o setaddress.o server.o

udpserver : $(objects)
	gcc -o udpserver  $(objects)
setaddress.o : setaddress.c
	gcc -c setaddress.o setaddress.c
server.o : server.c
	gcc -c server.o server.c
clean : 
	rm udpserver $(objects)

