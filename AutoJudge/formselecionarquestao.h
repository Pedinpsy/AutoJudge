#ifndef FORMSELECIONARQUESTAO_H
#define FORMSELECIONARQUESTAO_H

#include <QDialog>

namespace Ui {
class formSelecionarQuestao;
}

class formSelecionarQuestao : public QDialog
{
    Q_OBJECT

public:
    explicit formSelecionarQuestao(QString usuario, QString numero, QWidget *parent = 0);
    ~formSelecionarQuestao();

private slots:
    void on_pushButton_clicked();

    void on_ok_accepted();

private:
    Ui::formSelecionarQuestao *ui;
};

#endif // FORMSELECIONARQUESTAO_H
