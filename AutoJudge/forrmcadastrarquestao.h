#ifndef FORRMCADASTRARQUESTAO_H
#define FORRMCADASTRARQUESTAO_H

#include <QWidget>

namespace Ui {
class ForrmCadastrarQuestao;
}

class ForrmCadastrarQuestao : public QWidget
{
    Q_OBJECT

public:
    explicit ForrmCadastrarQuestao(QWidget *parent = 0);
    ~ForrmCadastrarQuestao();

private:
    Ui::ForrmCadastrarQuestao *ui;
};

#endif // FORRMCADASTRARQUESTAO_H
