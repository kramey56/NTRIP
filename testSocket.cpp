#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netdb.h>

#include "SocketInterfaceDevice.h"

using namespace std;

int main()
{
        //char	request2[] = "GET / HTTP/1.1\r\n";
        char    request2[] = "GET /HGPS_TEST_DFX HTTP/1.1\r\nAuthorization: Basic SEdQU19URVNUOmFiYzEyMw==\n\r\n";
        char*	response;
        char	host[] = "208.77.60.71";
        int     rBytes = 0;
        int     wBytes = 0;
	SocketInterfaceDevice*		casterSocket;
	casterSocket = new SocketInterfaceDevice();

        casterSocket->open(host, 5000, 5);

        wBytes = casterSocket->write(request2, strlen(request2));
        if (wBytes < 0)
	{
	   cout << "Write error...";
           return wBytes;
	}

        do
        {
            response = new char[51];
            rBytes = casterSocket->read(response, 50);
            response[51] = '\0';
            cout << response;
            delete response;
        }
        while (rBytes > 0);
        if (rBytes < 0)
	{
	   cout << "Read error...";
           return rBytes;
	}

	return 0;
}
