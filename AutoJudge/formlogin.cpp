#include "formlogin.h"
#include "ui_formlogin.h"
#include "paineldecontrole.h"
#include <QMessageBox>
#include "bancodedados.h"
#include "questoes.h"
#include <stdio.h>

formLogin::formLogin(QWidget *parent) : //construtor de login seta ui do login e seta o tamanho da tela
    QWidget(parent),
    ui(new Ui::formLogin)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());//Deixa o tamanho do form statico

}

formLogin::~formLogin() //desconstrutor
{
    delete ui;
}



void formLogin::on_pushButton_clicked() //verifica se tem cadastro
{
    if(ui->lineLogin->text().size()>4){
        FILE *arq;
        char *cc = ui->lineLogin->text().toLatin1().data();
        QString aux = QString("cd Documentos; cd autojudge;  if [ -d '%1' ]; then cd %2; else mkdir '%3' && cd '%4' && touch numero; fi").arg(cc,cc,cc,cc);
        QString aux2 = QString("/home/pedro/Documentos/autojudge/%1/numero").arg(ui->lineLogin->text().toLatin1().data());
        system(aux.toLatin1().data());//verifica se tem uma pasta com o noem do login, caso nao tenha é criada
        if(get_size(aux2.toLatin1().data())==0){
            arq = fopen(aux2.toLatin1().data(),"w");
            fprintf(arq,"%d",1);
            fclose(arq);

        }



        this->hide();//esconde o formulario de login
        PainelDeControle *asd = new PainelDeControle(ui->lineLogin->text(),this);//Inicializa a classe com um formuladrio do tipo
         asd->show();//Mostra o formulario na tela      // painel de controle e passa como parametro para
                                                     //o construtor o nome de login do usuario

      criarConexao();

    }else{
        QMessageBox asd;
        asd.setText("Digite um login maior que 4 letras");
        asd.exec();

    }


}



int get_size(const char* file_name)
{
    FILE *file = fopen(file_name, "r");

    if(file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}
