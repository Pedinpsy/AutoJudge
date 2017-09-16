#include "bancodedados.h"
#include <QString>
#include <QtSql/qsql.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>

QString bd ="/home/pedro/AutoJudge/lp";
QSqlDatabase db;

bool criarConexao(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(bd);
    if (!db.open()) {
          printf("deu ruim");
        return false;
    }

    return true;
}
void inserirQuestao(QString usuario,QString entrada, QString saida, QString titulo,QString enunciado){
    QSqlQuery query;
    query.exec("insert into questao(usuario, entrada, saida, titulo, enunciado) values('"+usuario+"','"+entrada+"', '"+saida+"', '"+titulo+"','"+enunciado+"')");
   // query.exec("insert into usuario values('"+usuario+"','"+titulo+"')");
    query.next();
}

void mostrarTabela(QSqlQueryModel *tabela){

     QSqlQuery *query = new QSqlQuery(db);
     query->prepare("select numero,usuario,titulo,enunciado from questao");
     query->exec();
     tabela->setQuery(*query);
}
void cadastrarResposta(QString fonte,QString numero, QString usuario, QString saida,QString tempo){
    QSqlQuery query;
    query.exec("insert into resposta(usuario,fonte,numeroQuestao,saida,tempo) values('"+usuario+"','"+fonte+"','"+numero+"','"+saida+"','"+tempo+"')");

}

QString retornaSaida(QString numero ){
    QSqlQuery query;
    query.prepare("select saida from questao where numero = "+numero+"");
    query.exec();
    //query.exec("select entrada from questao where numero = "+numero+"");
    while(query.next()){
        return query.value(0).toString();

    }
    return NULL;
}

QString retornaEntrada(QString numero ){

    QSqlQuery query;
    query.prepare("select entrada from questao where numero = "+numero+"");
    query.exec();
    //query.exec("select entrada from questao where numero = "+numero+"");
    while(query.next()){
        return query.value(0).toString();

    }
    return NULL;
}
void mostrarTabelaResposta(QSqlQueryModel *tabela){
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("select * from resposta");
    query->exec();
    tabela->setQuery(*query);



}


