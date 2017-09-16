#ifndef FORMCADASTRARQUESTAO_H
#define FORMCADASTRARQUESTAO_H


#include <QWidget>
#include <QString>
#include <QtSql/qsql.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>

bool createConnection();
namespace Ui {
class formCadastrarQuestao;
}

class formCadastrarQuestao : public QWidget
{
    Q_OBJECT

public:
    explicit formCadastrarQuestao(QString c, QWidget *parent = 0);
    ~formCadastrarQuestao();


private slots:
    void on_btnSelecionarEntrada_clicked();

    void on_pushButton_clicked();

    void on_btnCadastrarQuestao_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::formCadastrarQuestao *ui;
};

#endif // FORMCADASTRARQUESTAO_H
