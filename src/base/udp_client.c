#include <sys/errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "macros.h"
#include "error.h"
#include "set_address.h"
#include "udp_client.h"

int udp_client(char *hname, char *sname,
		struct sockaddr_in *sap)
{
	int s;
	
	set_address(hname, sname, sap, "udp");
	s = socket(AF_INET, SOCK_DGRAM, 0);
	if (!isvalidsock(s))
		error(1, errno, "socket call failed");
	return s;
}
