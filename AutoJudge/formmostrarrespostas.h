#ifndef FORMMOSTRARRESPOSTAS_H
#define FORMMOSTRARRESPOSTAS_H

#include <QWidget>

namespace Ui {
class FormMostrarRespostas;
}

class FormMostrarRespostas : public QWidget
{
    Q_OBJECT

public:
    explicit FormMostrarRespostas(QWidget *parent = 0);
    ~FormMostrarRespostas();

private:
    Ui::FormMostrarRespostas *ui;
};

#endif // FORMMOSTRARRESPOSTAS_H
