#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "../base/macros.h"
#include "../base/set_address.h"

char *program_name;

int main(int argc, char **argv)
{
    struct sockaddr_in local;
    struct sockaddr_in peer;
    char *hname;
    char *sname;
    int peerlen;
    int s1;
    int s;
    const int on = 1;

    INIT();

    if (argc == 2) {
        hname = NULL;
        sname = argv[1];
    } else {
        hname = argv[1];
        sname = argv[2];
    }

    set_address(hname, sname, &local, "tcp");
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (!isvalidsocket(s))
        error(1, errno, "socket call failed");
    if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on,
        sizeof(on)))
        error(1, errno, "setsockopt failed");
    if (bind(s, (struct sockaddr *)&local, sizeof(local)))
        error(1, errno, "bind failed");
    if (listen(s, NLISTEN))
        error(1, errno, "listen failed");

    do {
        peerlen = sizeof(peer);
        s1 = accept(s, (struct sockaddr *)&peer, &peerlen);
        if (!isvalidsock(s1))
            error(1, errno, "accept failed");
        server(s1, &peer);
        CLOSE(s1);
    } while (1);

    EXIT(0);
}
