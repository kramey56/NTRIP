/** @file SocketInterfaceDevice.h
 *
 * @brief Provide an interface for socket-based communications
 *
 * @par
 * Copyright Hemisphere GPS (c) 2010
 * All rights reserved.
 */

#ifndef PORT_INTERFACE_DEVICE_H
#define PORT_INTERFACE_DEVICE_H

#include <string>
#include <stdexcept>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>
#include <stdio.h>

class SocketInterfaceDevice
{
    public:
		// Initialize port connection
        int open(const char* host, int port, int timeOut);
		// Close port after use
        int close();
		// Read len characters into buffer. Return actual character count.
        int read(char* buffer, int len);
		// Write up to len characters from buffer. Return actual write count.
        int write(const char* buffer, unsigned int len);

    private:
        int             socketFD;			// Socket file descriptor
        int             timeOutSecs;		// Seconds to allow before timeout
        char            resolvedIP[16];		// Host IP address
        fd_set          fds;				// Set of active file descriptors
        struct          timeval timeout;	// Time structure for timeout
};

#endif // PORT_INTERFACE_DEVICE_H
