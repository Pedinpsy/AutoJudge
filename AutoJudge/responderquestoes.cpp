#include "responderquestoes.h"
#include "ui_responderquestoes.h"
#include "bancodedados.h"
#include <QFileDialog>
#include "formselecionarquestao.h"

QString numeroQuestao = "null";
QString nomeUsuario;
ResponderQuestoes::ResponderQuestoes(QString c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResponderQuestoes)
{
     nomeUsuario= c;
    ui->setupUi(this);
    QSqlQueryModel *tabela = new QSqlQueryModel() ;
    mostrarTabela(tabela);
    ui->tableView->setModel(tabela);
}

ResponderQuestoes::~ResponderQuestoes()
{
    delete ui;
}

void ResponderQuestoes::on_pushButton_clicked()
{
 formSelecionarQuestao *questao = new formSelecionarQuestao(nomeUsuario,numeroQuestao,this);
 questao->show();
}

void ResponderQuestoes::on_tableView_activated(const QModelIndex &index)
{
    QString enunciado = ui->tableView->model()->data(index).toString();
    ui->textBrowser->setText(index.sibling(index.row(),3).data().toString());
    numeroQuestao = index.sibling(index.row(),0).data().toString();
}

void ResponderQuestoes::on_tableView_clicked(const QModelIndex &index)
{
    ui->textBrowser->setText(index.sibling(index.row(),3).data().toString());
    numeroQuestao = index.sibling(index.row(),0).data().toString();

}
