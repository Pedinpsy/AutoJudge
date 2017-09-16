#include "formmostrarrespostas.h"
#include "ui_formmostrarrespostas.h"
#include "bancodedados.h"

FormMostrarRespostas::FormMostrarRespostas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMostrarRespostas)
{
    ui->setupUi(this);
    QSqlQueryModel *tabela = new QSqlQueryModel() ;
    mostrarTabelaResposta(tabela);
    ui->tableView->setModel(tabela);
}

FormMostrarRespostas::~FormMostrarRespostas()
{
    delete ui;
}
