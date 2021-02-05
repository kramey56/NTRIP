#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "ntrip_corrector.h"
#include "SocketInterfaceDevice.h"

// Following line allows cerr to trace NTRIP data output
// #define TRACE 1

NTRIPCorrector::NTRIPCorrector
        (SocketInterfaceDevice* upLink,
        HemisphereGPS::Common::DeviceCommInterface* downLink,
        const std::string user,const std::string pw,const std::string host,
        const std::string port,const std::string mtPoint, int toVal)

{
    m_userID = user;
    m_userPW = pw;
    m_hostName = host;
    m_hostPort = port;
    m_hostMount = mtPoint;
    m_netPort = upLink;
    m_gpsPort = downLink;
    m_timeOut = toVal;
}

NTRIPCorrector::~NTRIPCorrector()
{
}

static char base64Vals[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                           "abcdefghijklmnopqrstuvwxyz"
                           "0123456789+/";

const char *NTRIPCorrector::encrypt_base64(const char *input, size_t len)
{
    char            *output;
    char            *p;
    size_t          i = 0;
    size_t          mod = len %3;

    p = output = (char *) malloc(((len / 3) + (mod ? 1 : 0)) * 4 + 1);
    if (!p)
        return 0;

    while (i < len - mod)
    {
        *p++ = base64Vals[input[i++] >> 2];
        *p++ = base64Vals[((input[i - 1] << 4) | (input[i] >> 4)) & 0x3f];
        *p++ = base64Vals[((input[i] << 2) | (input[i + 1] >> 6)) & 0x3f];
        *p++ = base64Vals[input[i + 1] & 0x3f];
        i += 2;
    };

    if (!mod)
    {
        *p = 0;
        return output;
    }
    else
    {
        *p++ = base64Vals[input[i++] >> 2];
        *p++ = base64Vals[((input[i - 1] << 4) | (input[i] >> 4)) & 0x3f];
        if (mod == 1)
        {
            *p++ = '=';
            *p++ = '=';
            *p = 0;
            return output;
        }
        else
        {
            *p++ = base64Vals[(input[i] << 2) & 0x3f];
            *p++ = '=';
            *p = 0;
            return output;
        }
    }
}

int NTRIPCorrector::initSession()
{
    int len = 0;
    int retry = 0;
    char* response = new char[50];

    string auth (m_userID);
    auth.append(1,':');
    auth.append(m_userPW);

    m_connectionStatus = UNCONNECTED;

    int rc = m_netPort->open(m_hostName.c_str(), atoi(m_hostPort.c_str()), m_timeOut);
    if ( rc < 0 )
    {
        return NOSOCKET;
    }

    string* httpRequest = new string("GET /");
    httpRequest->append(m_hostMount);
    httpRequest->append(" HTTP/1.0\r\n");
    //httpRequest->append("Host: ");
    //httpRequest->append(hostName);
    //httpRequest->append(":");
    //httpRequest->append(hostPort);
    //httpRequest->append("\r\n");
    // httpRequest->append("Ntrip-Version: Ntrip/2.0\r\n");
    httpRequest->append("User-Agent: HGPS NtripClientPOSIX/1.0\r\n");
    httpRequest->append("Accept: */*\r\n");
    httpRequest->append("Connection: close\r\n");
    httpRequest->append("Authorization: Basic ");
    httpRequest->append(encrypt_base64(auth.c_str(), auth.length()));
    httpRequest->append("\r\n\r\n");
    // Send the log-in string to the internet server
    int writeLen = httpRequest->length();
    netPort->write(httpRequest->c_str(), writeLen);

    rc = m_netPort->read(response, 50);
    if (rc < 0)
    {
        return READFAIL;
    }
    else
        return checkConnection(response);
   }

void NTRIPCorrector::processNTRIPData()
{
    int dataLen = 200;
    char* readData = new char[dataLen];
    int rc = m_netPort->read(readData, dataLen);
    if (rc == 0)
    {
        m_connectionStatus = TIMEOUT;
    }
    else
    {
        m_gpsPort->dataOut(readData, rc);
    }
#ifdef TRACE
    cout << readData;
#endif
    delete readData;
}

int NTRIPCorrector::checkConnection(const char *inData)
{
    size_t found;
    int rc = 0;

    string response(inData);

    found = response.find("20");
    if (found != string::npos)
    {
        m_connectionStatus = CONNECTED;
    }
    else
    {
        // Not connected - could be 401 - invalid user/pw or 404 - unknown
        found = response.find("401");
        if (found != string::npos)
        {
            m_connectionStatus = SECURITYFAIL;
            rc = SECURITYFAIL;
        }
        else
        {
            m_connectionStatus = UNKNOWN;
            rc = UNKNOWN;
        }
    }
    return rc;
}

NTRIPCorrector::LinkStatus NTRIPCorrector::connectionHealth()
{
    return m_connectionStatus;
}
