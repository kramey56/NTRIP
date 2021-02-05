#ifndef CORRECTOR_CTL_H
#define CORRECTOR_CTL_H

#include "ntrip_corrector.h"
#include <QTimer>

#define RETRY_LIMIT 5

class CorrectorController : public QObject
{
    Q_OBJECT
public:
    /**
    *
    *Constructor - creates needed timers, initializes private members, connects
    *up QT signals for handling I/O and gets the system ready to start processing
    *corrector data.
    *
    *@author Ken Ramey
    *
    */

    CorrectorController(NTRIPCorrector* myChan, int timeOutVal);

    /**
    *
    *Destructor - stops timers and destroys them properly
    *
    *@author Ken Ramey
    *
    */

    ~CorrectorController();

private:
///The data channel that gets corrector data and translates it
    NTRIPCorrector*             m_corrector;
///Timer to make sure we check for data periodically
    QTimer*                     m_processTimer;

signals:
    void noConnection();
    void lostConnection();

public slots:
    /**
    *
    *checkData() - this method calls a method that reads data from the socket to
    *the server and copies it to the serial port connected to the GPS device.  If
    *there is a timeout on the read, then it retries up to five times before
    *signaling a read error.
    *
    *@author Ken Ramey
    *
    */

    void checkData();

    /**
    *
    *start() - this method initializes and starts the two timers used to control
    *operation of the corrector object.  processTimer is used to make sure we check
    *for new input every 500 ms.  dataTimer starts out at our chosen timeout
    *value and gets reset every time we read data in. If it ever fires, it means
    *that we went the entire timeout period without seeing any new data arrive and
    *have timed out on the intput channel.
    *
    *@author Ken Ramey
    *
    */

    void start();
};

#endif // CORRECTOR_CTL_H
