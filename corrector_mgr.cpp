#include "corrector_mgr.h"
#include "SocketInterfaceDevice.h"

#include <QString>

CorrectorMgr::CorrectorMgr(QObject *parent, QString* userId, QString* password,
                           QString* ntripHost, QString* hostPort,
                           QString* mount, int timeOut) :
    QObject(parent)
{
    m_uID = *userId;
    m_uPW = *password;
    m_hName = *ntripHost;
    m_hPort = *hostPort;
    m_hMount = *mount;
    m_tOut = timeOut;

    buildCorrector(userId, password, ntripHost, hostPort, mount, timeOut);
}

CorrectorMgr::~CorrectorMgr()
{
    m_processThread->quit();

    if (m_ntripController)
    {
        delete m_ntripController;
        m_ntripController = NULL;
    }

    if (m_readyCorrector)
    {
        delete m_readyCorrector;
        m_readyCorrector = NULL;
    }

    if (m_netPort)
    {
        m_netPort->close();
        delete m_netPort;
        m_netPort = NULL;
    }

    if (m_gpsPort)
    {
        m_gpsPort->close();
        delete m_gpsPort;
        m_gpsPort = NULL;
    }

    m_processThread->wait();
    delete m_processThread;
    m_processThread = NULL;
}

void CorrectorMgr::buildCorrector(QString* userId, QString* password,
                                  QString* ntripHost, QString* hostPort,
                                  QString* mount, int timeOut)
{
    int portNum = hostPort->toInt();

    m_netPort = new SocketInterfaceDevice();
    m_gpsPort = new HemisphereGPS::Common::SerialPortDevice(NULL, GPSPORT);
    m_gpsPort->open();

    m_readyCorrector = new NTRIPCorrector(m_netPort, m_gpsPort, userId->toStdString(),
                                        password->toStdString(),
                                        ntripHost->toStdString(),
                                        hostPort->toStdString(),
                                        mount->toStdString(), timeOut);

    m_ntripController = new CorrectorController(m_readyCorrector, timeOut);

    m_processThread = new QThread();
    m_ntripController->moveToThread(processThread);
    connect(m_processThread, SIGNAL(started()), m_ntripController, SLOT(start()));
    connect(m_ntripController, SIGNAL(lostConnection()), this, SLOT(resetComms()));
    connect(m_ntripController, SIGNAL(noConnection()), this, SLOT(connectFailed()));
    m_processThread->start();
}

void CorrectorMgr::resetComms()
{
    emit(commsDown(LINK_LOST));
}

void CorrectorMgr::connectFailed()
{
    emit(commsDown(NO_LINK));
}
