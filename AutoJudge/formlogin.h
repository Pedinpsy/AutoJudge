#ifndef FORMLOGIN_H
#define FORMLOGIN_H
#include "paineldecontrole.h"

#include <QWidget>
int get_size(const char* file_name);

namespace Ui {
class formLogin;
}

class formLogin : public QWidget
{
    Q_OBJECT

public:
    explicit formLogin(QWidget *parent = 0);
    ~formLogin();


public:
    Ui::formLogin *ui;
private slots:
    void on_pushButton_clicked();

};

#endif // FORMLOGIN_H
