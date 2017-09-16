#ifndef BANCODEDADOS_H
#define BANCODEDADOS_H
#include <QString>
#include <QtSql/qsql.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>

    void cadastrarResposta(QString fonte, QString numero, QString usuario, QString saida, QString tempo);
    void mostrarTabela(QSqlQueryModel *tabela);
    bool criarConexao();
    void inserirQuestao(QString usuario,QString entrada, QString saida, QString titulo,QString enunciado);
    QString retornaSaida(QString numero );
    QString retornaEntrada(QString numero );
    void mostrarTabelaResposta(QSqlQueryModel *tabela);

#endif // BANCODEDADOS_H
