#ifndef CORRECTOR_MGR_H
#define CORRECTOR_MGR_H

#include <QObject>
#include <QThread>
#include <QString>
#include "HemisphereGPS/Common/SerialPortDevice.h"
#include "HemisphereGPS/Common/Timer.h"
#include "ntrip_corrector.h"
#include "corrector_ctl.h"
#include "SocketInterfaceDevice.h"

#define GPSPORT "/dev/ttyUSB0, 19200, 8, n, 1"

/**
*
*@class CorrectorMgr
*
*@brief Creates objects needed to process NTRIP corrector data
*
*The CorrectorMgr class creates the communication ports, NTRIP controller and
*NTRIP corrector.  It then connects them up, puts the controller in a thread
*and starts the process running.
*
*@author Ken Ramey
*
*/

class CorrectorMgr : public QObject
{
    Q_OBJECT
public:
    enum CommReason {LINK_LOST, NO_LINK};

    /**
    *
    *Constructor - This method creates an instance of the CorrectorMgr and
    *initializes parameters needed to establish and maintain the connection with
    *the internet caster.
    *
    *@param parent - reference back to our creator
    *@param userid - pointer to a string with the login username in it
    *@param password - pointer to a string hoding the login password
    *@param ntripHost - pointer to string holding name or ip address of host
    *@param hostPort - pointer to string holding number of port to connect to
    *@param mount - pointer to string holding name of mountpoint to attach
    *
    *@author Ken Ramey
    *
    */

    explicit CorrectorMgr(QObject *parent = 0, QString* uid = 0, QString* upw = 0,
                          QString* nh = 0, QString* hp = 0, QString* mt = 0,
                          int to = 5);

    /**
    *
    *Destructor - deletes all class instances created during initialization,
    *closes I/O ports, and terminates thread used for event processing.
    *
    *@author Ken Ramey
    *
    */

    ~CorrectorMgr();

public slots:
    void connectFailed();
    void resetComms();

signals:
    void commsDown(int rc);

private:
    /**
    *
    *buildCorrector - This method does most of the work of setting up the
    *NTRIP corrector and its controller.
    *
    *@author Ken Ramey
    *
    */

    void buildCorrector(QString*,QString*,QString*,QString*,QString*,int);

///The NTRIP correction handler
    NTRIPCorrector*                             m_readyCorrector;
///A light-weight QT object to handle I/O events
    CorrectorController*                        m_ntripController;
///I/O port that talks to the internet connection
    SocketInterfaceDevice*                      m_netPort;
///I/O port for sending corrector data to the GPS
    HemisphereGPS::Common::SerialPortDevice*    m_gpsPort;
///Thread to hold the QT wrapper
    QThread*                                    m_processThread;
///Storage for operating values
    QString                                     m_uID;
    QString                                     m_uPW;
    QString                                     m_hName;
    QString                                     m_hPort;
    QString                                     m_hMount;
    int											m_tOut;

};

#endif // CORRECTOR_MGR_H
