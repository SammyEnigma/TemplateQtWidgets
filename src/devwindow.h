#ifndef DEVWINDOW_H
#define DEVWINDOW_H

#include <QDialog>

namespace Ui {
class DevWindow;
}

class DevWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DevWindow(QWidget *parent = nullptr);
    ~DevWindow();

private:
    Ui::DevWindow *ui;
};

#endif // DEVWINDOW_H
