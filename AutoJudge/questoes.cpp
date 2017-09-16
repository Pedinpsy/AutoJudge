#include "questoes.h"
#include <QMessageBox>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QString>
#include <QCoreApplication>
typedef struct _questao{
    QString titulo;
    QString enunciado;
    QString entrada;
    QString saida;
    struct _questao *prox;
}questao;


void inicia (questao *lista){
 lista->prox=NULL;
}
questao *aloca(QString titulo,QString enunciado, QString entrada,QString saida){
    questao *node = (questao*)malloc(sizeof(questao));
    if (!node){ //testa se deu certo a alocaçao de memoria
        QMessageBox msgBox;
        msgBox.setText("Erro de memoria");//caso nao tenha alocado memoria mostra erro
        msgBox.exec();
        exit(1);
    }else{
    node->entrada=entrada;
    node->enunciado=enunciado;
    node->saida=saida;
    node->titulo=titulo;
    return node;
    }



}

bool compararSaidas(QString saida1,QString saida2){
    bool flag = true;
    int linha1 = 0;
    int linha2 = 0;
    FILE *arq1,*arq2;
    char resultado1[100],resultado2[100];
    arq1 = fopen(saida1.toLatin1().data(),"r");
    arq2 = fopen(saida2.toLatin1().data(),"r");
    fgets(resultado2,100,arq2);
    linha2++;
    fgets(resultado1,100,arq1);
    linha1++;
    QMessageBox msgBox;
    msgBox.setText("Acerto");
    QMessageBox msgBoxx;
    QString error;

    while(feof(arq1)!= 1 || feof(arq2) != 1){

        if(strcmp(resultado1, resultado2)!=0){
            msgBox.setText("Erro");


           QCoreApplication::processEvents();
           flag = false;

            error = QString("Diferenca entra a linha: %1 e a linha:%2 \n >%3 > %4 .").arg(QString::number(linha1),QString::number(linha2),resultado1,resultado2);
            msgBoxx.setText(error);
            msgBoxx.exec();
             msgBox.show();

        }
        if (feof(arq2) == 0){fgets(resultado2,100,arq2);linha2++;}
        if (feof(arq1) == 0){fgets(resultado1,100,arq1);linha1++;}

    }
        msgBox.exec();
        msgBox.show();
        return flag;

}
