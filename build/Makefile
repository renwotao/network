udpserver : udpserver.o setaddress.o server.o
	gcc -o udpserver  udpserver.o setaddress.o server.o
setaddress.o : setaddress.c
	gcc -c setaddress.o setaddress.c
server.o : server.c
	gcc -c server.o server.c
clean : 
	rm udpserver udpserver.o setaddress.o server.o

