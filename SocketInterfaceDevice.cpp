/** @file SocketInterfaceDevice.cpp
 *
 * @brief Provides implementation of interface for network communications
 *
 * @par
 * Copyright Hemisphere GPS (c) 2010
 * All rights reserved.
 */

#include <netdb.h>
#include <string.h>
#include <cstdlib>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "SocketInterfaceDevice.h"

int SocketInterfaceDevice::open(const char* host, int hostPort, int timeOutVal)
{
    struct sockaddr_in serv_addr;
    struct hostent *server;
    struct in_addr h_addr;
    bool hostIP = true;

    timeOutSecs = timeOutVal;
    int hostLen = strlen(host);
    int i = 0;
    while ((i < hostLen) && hostIP)
    {
        if (isalpha(host[i]))
            hostIP = false;
        i++;
    }

    if (!hostIP)
    {
        server = gethostbyname(host);
        h_addr.s_addr = *((unsigned long *) server->h_addr_list[0]);
        strcpy(resolvedIP, inet_ntoa(h_addr));
    }
    else
    {
        strcpy(resolvedIP, host);
    }

    socketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketFD < 0)
    {
        // Failed to create socket, so pass that info up the chain
        return socketFD;
    }

    FD_ZERO(&fds);
    FD_SET(socketFD, &fds);

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(resolvedIP);
    serv_addr.sin_port = htons(hostPort);
    int rc = connect(socketFD, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    return rc;
}

int SocketInterfaceDevice::close()
{
    ::close(socketFD);
    return 0;
}

int SocketInterfaceDevice::read(char* data, int bytes)
{
    timeout.tv_sec = timeOutSecs;
    timeout.tv_usec = 0;

    int rc = select(sizeof(fds)*8, &fds, NULL, NULL, &timeout);
    if (rc > 0)
    {
        rc = ::read(socketFD, data, bytes);
    }

    return rc;
}

int SocketInterfaceDevice::write(const char* data, unsigned int len)
{
    int rc;

    if (len > 0)
    {
        rc = ::write(socketFD, data, len);
    }

    return rc;
}
