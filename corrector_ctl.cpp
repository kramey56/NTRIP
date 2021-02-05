#include "corrector_ctl.h"
#include <QThread>

// The CorrectorController class provides a framework for starting
// and managing operation of the corrector, which actually receives
// and processes NTRIP correction data.	
// Has a data connection to the corrector and, eventually
// will have a deault timeout limit									 
CorrectorController::CorrectorController(NTRIPCorrector* dataChan,
                                         int timeOutLim)
{
	m_corrector = dataChan;
}

CorrectorController::~CorrectorController()
{
}

// Start up a corrector. Allow 500 msec for connection to be made
// and data to be available.
void CorrectorController::start()
{
    m_processTimer = new QTimer(this);
    int rc = m_corrector->initSession();
    if (rc == 0)
    {
        connect(m_processTimer, SIGNAL(timeout()), this, SLOT(checkData()));
        m_processTimer->start(500);
    }
    else
    {
        // emit a signal to be caught above
        m_processTimer->stop();
        emit noConnection();
    }
    QThread::yieldCurrentThread();
}

// Check that we have usable data from the corrector. If we go RETRY_LIMIT attempts
// without data, consider the channel to be dead.
void CorrectorController::checkData()
{
    int retries = 0;
    do
    {
        retries++;
        m_corrector->processNTRIPData();
    }
    while ((retries < RETRY_LIMIT) &&
           (m_corrector->connectionHealth() == NTRIPCorrector::TIMEOUT));
    if (retries == RETRY_LIMIT)
    {
        m_processTimer->stop();
        emit lostConnection();
    }
    QThread::yieldCurrentThread();
}
