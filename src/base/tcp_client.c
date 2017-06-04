#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "tcp_client.h"

int tcp_client( char *hname, char *sname) 
{
    struct sockaddr_in peer;
    int s;

    set_address( hname, sname, &peer, "tcp" );
    s = socket( AF_INET, SOCK_STREAM, 0 );
    if ( !isvalidsock( s ) ) 
        error( 1, errno, "socket call failed" );

    if ( connect( s, ( struct sockaddr * )&peer,
        sizeof( peer ) ) )
        error( 1, errno, "connect failed" );

    return s;
}
