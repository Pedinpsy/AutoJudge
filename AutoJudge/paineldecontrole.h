#ifndef PAINELDECONTROLE_H
#define PAINELDECONTROLE_H
#include "formlogin.h"

#include <QMainWindow>

namespace Ui {
class PainelDeControle;
}

class PainelDeControle : public QMainWindow
{
    Q_OBJECT

public:
    explicit PainelDeControle(QString i, QWidget *parent = 0);
    ~PainelDeControle();

public:
    Ui::PainelDeControle *ui;
private slots:
    void on_actionCadastrarQuestao_triggered();
    void on_actionResponder_Quest_o_triggered();
    void on_actionMostrar_Respostas_triggered();
};


#endif // PAINELDECONTROLE_H
