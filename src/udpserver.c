#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#include "../framework/skel.h"
#include "../framework/etcp.h"

char *program_name;

int main(int argc, char** argv) {
	struct sockaddr_in local;
	char *hname;
	char *shname;
	SOCKET s;
	
	INIT();
	if (argc == 2) {
		hname = NULL;
		shname = argv[1];
	} else {
		hname = argv[1];
		shname = argv[2];
	}

	set_address(hname, shname, &local, "udp");
	s = socket(AF_INET, SOCK_DGRAM, 0);
	if (!isvalidsock(s)) {
		error(1, errno, "socket call failed");
	}
	if (bind(s, (struct sockaddr*)&local, sizeof(local))) {
		error(1, errno, "bind failed");
	}

	server(s, &local);
	EXIT(0);
}
