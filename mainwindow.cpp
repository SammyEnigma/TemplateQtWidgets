#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Fill the menu by language actions
    ui->menuLanguage->addActions(_i18n.buildActions(ui->menuLanguage));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAboutQt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionAboutSoftware_triggered()
{
    QString text =
            QCoreApplication::applicationName() + " " + QCoreApplication::applicationVersion() + "\n" +
            tr("Organization: %1").arg(QCoreApplication::organizationName()) + "\n" +
            QCoreApplication::organizationDomain() + "\n" +
            tr("Qt: %1 %2").arg(qVersion()).arg(QSysInfo::buildCpuArchitecture()) + "\n" +
            tr("Build Date and Time: %1 %2").arg(__DATE__).arg(__TIME__);

    QMessageBox::about(this, tr("About Software"), text);
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::changeEvent(QEvent *event){
    QMainWindow::changeEvent(event);
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
        ui->menuLanguage->setIcon(_i18n.currentIcon());
        qDebug("Language changed");
    }
}
