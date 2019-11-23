#include "devwindow.h"
#include "ui_devwindow.h"

DevWindow::DevWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DevWindow)
{
    ui->setupUi(this);
}

DevWindow::~DevWindow()
{
    delete ui;
}
