#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "I18nManager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAboutQt_triggered();
    void on_actionAboutSoftware_triggered();
    void on_actionExit_triggered();

protected:
    void changeEvent(QEvent *event);

private:
    Ui::MainWindow *ui;
    I18nManager _i18n;

};

#endif // MAINWINDOW_H
