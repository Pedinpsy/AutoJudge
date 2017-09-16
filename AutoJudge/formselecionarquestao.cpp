#include "formselecionarquestao.h"
#include "ui_formselecionarquestao.h"
#include <QFileDialog>
#include "bancodedados.h"
#include <QMessageBox>
#include "questoes.h"
#include <time.h>
QString usr;
formSelecionarQuestao::formSelecionarQuestao(QString usuario,QString numero, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formSelecionarQuestao)
{
    usr= usuario;
    ui->setupUi(this);
    ui->label_2->setText(numero);
}

formSelecionarQuestao::~formSelecionarQuestao()
{
    delete ui;
}

void formSelecionarQuestao::on_pushButton_clicked()
{
   ui->label_3->setText( QFileDialog::getOpenFileName(this,
                                                      tr("Selecione o codigo Fonte"), "/home", tr("cpp(*.cpp)")));
}

void formSelecionarQuestao::on_ok_accepted()
{

    if(ui->label_3->text() == "Nenhum arquivo selecionado" || ui->label_3->text() == NULL){
     QMessageBox::information(this,tr(""),"insira um codigo fonte valido");
    }else
    {
        clock_t tempoInicial,tempoFinal;
        float tempoExec;
        QString diretorio = QString("/home/pedro/Documentos/autojudge/%1/numero").arg(usr);
        FILE *arq = fopen(diretorio.toLatin1().data(),"r");
        int numero;
        fscanf(arq,"%d",&numero);
        arq = fopen(diretorio.toLatin1().data(),"w");
        fprintf(arq,"%d",numero+1);
        fclose(arq);
        QString saida = QString("/home/pedro/Documentos/autojudge/%1/%2").arg(usr,QString::number(numero));
        QString aux = QString("cd Documentos ;cd autojudge; cd %1 ; g++ %2 -o exec; ./exec<%3>%4 ").arg(usr,ui->label_3->text(),retornaEntrada(ui->label_2->text()),QString::number(numero));
        tempoInicial = clock();
        system(aux.toLatin1().data());
        tempoFinal = clock();
        tempoExec = ((double)(tempoFinal-tempoInicial));


        QMessageBox::information(this,tr(""),saida);
        cadastrarResposta(ui->label_3->text(),ui->label_2->text(),usr,saida,QString::number(tempoExec));
        compararSaidas(saida,retornaSaida(ui->label_2->text().toLatin1().data()));
        this->close();

    }

}
