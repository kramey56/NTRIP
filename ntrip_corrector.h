#ifndef NTRIP_CORRECTOR_H
#define NTRIP_CORRECTOR_H

#include <string>
#include "HemisphereGPS/Common/DeviceCommInterface.h"
#include "SocketInterfaceDevice.h"
using namespace std;

namespace HemisphereGPS {
    namespace Common {
        class DeviceCommInterface;
    }
}

/**
*
*@class NTRIPCorrector
*
*@brief This is the class that deals with the stream of NTRIP corrector data
*
*This class is designed so that it can be used in a QT environment by the
*addition of a controller class that intercepts QT events and translates them
*to calls to the methods defined in this class.  It can also be used in an
*embedded system without an  OS or support for threads, signals, slots, or
*timers.
*
*@author Ken Ramey
*
*/

class NTRIPCorrector
{
public:
    enum LinkStatus { UNCONNECTED, SECURITYFAIL, CONNECTED, UNKNOWN,
                      NOSOCKET, READFAIL, TIMEOUT};

    NTRIPCorrector(SocketInterfaceDevice* upLink,
                   HemisphereGPS::Common::DeviceCommInterface* downLink,
                   const std::string user,const std::string pw,const std::string host,
                   const std::string port,const std::string mtPoint, int toVal);
    ~NTRIPCorrector();

    /**
    *initSession initializes the session with the NTRIP caster by sending the
    *\"GET\" request with the host name/ip address, userid, logon password, and
    *mount point in HTTP format.  This should initiate a stream of HTTP data
    *containing GPS correction values.
    *
    * @return Return value indicates whether or not the session with the caster
    * has been established.  Possible return values: CONNECTED, UNCONNECTED,
    * NOSOCKET, SECURITYFAIL, UNKNOWN
    */

    int initSession();

    /**
    *processNTRIPData is called by the controller object to process NTRIP
    *correction data from the internet connection. It reads data from the caster,
    *translates it to a format usable by the GPS system, then sends it to the GPS
    *device.
    *
    */

    void processNTRIPData();
    LinkStatus connectionHealth();

private:
///Enum to keep track of whether or not we have a connection
    LinkStatus                                      m_connectionStatus;
///Interface for receiving data from internet connection
    SocketInterfaceDevice*                          m_netPort;
///Interface for sending translated corrector data to the GPS
    HemisphereGPS::Common::DeviceCommInterface*     m_gpsPort;
///Values needed to log on to the corrector caster
    string                                          m_userID;
    string                                          m_userPW;
    string                                          m_hostName;
    string                                          m_hostPort;
    string                                          m_hostMount;
    int                                             m_timeOut;

    /**
    *encrypt_base64 is a utility function that takes a username:password string and
    *encodes it into the base64 system.  It is not intended to provide security but
    *to protect a server against varying character sets in international use
    *situations.
    *
    *@param idPW A single string with the userid and password seperated by a colon
    *
    *@return Returns an encrypted version of the userid and password.
    */

    const char *encrypt_base64(const char *idPW, size_t cnt);
    int checkConnection(const char* inData);

protected:


};

#endif // NTRIP_CORRECTOR_H
