#include <sys/select.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stddef.h>

#include "base/macros.h"
#include "base/tcp_client.h"
#include "heartbeat.h"

char *program_name;

int main(int argc, char **argv)
{
	fd_set allfd;
	fd_set readfd;
	msg_t msg;
	struct timeval tv;
        int s;
	int rc;
	int heartbeats = 0;
	int cnt = sizeof( msg );
	
	INIT();
	s = tcp_client( argv[1], argv[2] );
	FD_ZERO( &allfd );
	FD_SET( s, &allfd );
	tv.tv_sec = T1;
	tv.tv_usec = 0;
	for ( ;; ) {
		readfd = allfd;
		rc = select( s + 1, &readfd, NULL, NULL, &tv );
		if ( rc < 0 )
			error( 1, errno, "select failure" );
		if (rc == 0 ) {
			if ( ++heartbeats > 3 )
				error( 0, 0, "sending heartbeat #%d\n", heartbeats );
			msg.type = htonl( MSG_HEARTBEAT );
			rc = send( s, ( char* )&msg, sizeof( msg ), 0 );
			if ( rc < 0 )
				error( 1, errno, "send failure" );
			tv.tv_sec = T2;
			continue;
		}
		if ( !FD_ISSET( s, &readfd ) )
			error( 1, 0, "select returned invalid socket\n" );
		rc = recv( s, ( char * )&msg + sizeof( msg ) - cnt, cnt, 0);
		if ( rc == 0 )
			error( 1, errno, "recv failure" );
		heartbeats = 0;
		tv.tv_sec = T1;
		cnt -= rc;
		if ( cnt > 0 )
			continue;
		cnt = sizeof ( msg );
	}
}
