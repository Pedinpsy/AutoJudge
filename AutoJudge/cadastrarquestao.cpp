#include "formcadastrarquestao.h"
#include "ui_formcadastrarquestao.h"
#include <QString>
#include <QFileDialog>
#include <stdlib.h>
#include <QMessageBox>
#include <stdio.h>
#include <string.h>

#include "bancodedados.h"

typedef struct _questao{
  char* str;
}questao;

bool createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/pedro/AutoJudge/lp");


    if (!db.open()) {
          printf("deu ruim");
        return false;
    }

    return true;
}

QString cc;
formCadastrarQuestao::formCadastrarQuestao(QString c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::formCadastrarQuestao)
{
    cc=c;
    ui->setupUi(this);
    ui->label->setText(c);
}

formCadastrarQuestao::~formCadastrarQuestao()
{
    delete ui;
}

void formCadastrarQuestao::on_btnSelecionarEntrada_clicked()
{
    ui->lblEntrada->setText(QFileDialog::getOpenFileName());
}

void formCadastrarQuestao::on_pushButton_clicked()
{
    ui->lblSaida->setText(QFileDialog::getOpenFileName());
}

void formCadastrarQuestao::on_btnCadastrarQuestao_clicked(){


}
void formCadastrarQuestao::on_pushButton_2_clicked(){

}
void formCadastrarQuestao::on_pushButton_3_clicked()
{

if(ui->lblEntrada->text() == "Nenhuma entrada selecionada" || ui->lblEntrada->text() ==  NULL || ui->lblSaida->text() == "Nenhuma entrada selecionada" || ui->lblSaida->text() ==  NULL){
    QMessageBox::information(this,"Erro"," esta faltando entrada ou saida");
}else{
inserirQuestao(cc,ui->lblEntrada->text(),ui->lblSaida->text(),ui->lineTitulo->text(),ui->txtEnunciado->toPlainText());// passa como paramentro todos os campos referentes
  }                                                                                                                     //a questão e cadastra no bancod e dados
}
