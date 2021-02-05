#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// A simple QT window for testing the NTRIP corrector and associated
// controller and manager.
#include <QString>
#include <QMainWindow>

#include "../corrector_mgr.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow      *ui;
    CorrectorMgr        *myCorrector;

    // Test parameters
    //             user;  "HGPS_TEST"
    //             pw;    "abc123"
    //             host;  "208.77.60.71"
    //             port;  "5000"
    //             mtpt;  "ExampleStream"
    //             to;    "3"

private slots:
    void pbConnectClicked();
    void pbQuitClicked();
};

#endif // MAINWINDOW_H
