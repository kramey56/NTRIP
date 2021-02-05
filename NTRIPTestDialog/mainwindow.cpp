#include "mainwindow.h"
#include "ui_mainwindow.h"

// The main QT window. It preloads the default values for the
// server we use for testing.
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->leHostIP->setText("98.177.224.229");
    ui->leHostPort->setText("8025");
    ui->leMount->setText("NorthScottsdale");
    ui->leUserid->setText("Casey");
    ui->lePassword->setText("Hem!1");
    ui->leTimeout->setText("5");

    connect(ui->pbConnect, SIGNAL(clicked()), this, SLOT(pbConnectClicked()));
    connect(ui->pbQuit, SIGNAL(clicked()), this, SLOT(pbQuitClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Handle change of language for interface
void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::pbQuitClicked()
{
    qApp->quit();
}

// Respond to clicking of "Connect" button by creating
// a new corrector and initializing it.
void MainWindow::pbConnectClicked()
{
    bool ok;

    QString* host = new QString(ui->leHostIP->text());
    QString* port = new QString(ui->leHostPort->text());
    QString* mtpt = new QString(ui->leMount->text());
    QString* user = new QString(ui->leUserid->text());
    QString* pw   = new QString(ui->lePassword->text());
    QString* to   = new QString(ui->leTimeout->text());

    int toVal = to->toInt(&ok,10);

    myCorrector = new CorrectorMgr(this, user, pw, host, port, mtpt, toVal);
}
