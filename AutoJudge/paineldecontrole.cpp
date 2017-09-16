#include "paineldecontrole.h"
#include "ui_paineldecontrole.h"
#include <QMdiSubWindow>
#include "formlogin.h"
#include "formcadastrarquestao.h"
#include "responderquestoes.h"
#include <QString>
#include "formmostrarrespostas.h"
QString ii;

PainelDeControle::PainelDeControle(QString i, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PainelDeControle)
{
    ii=i;

    ui->setupUi(this);
    auto window=ui->mdiArea->addSubWindow(new formCadastrarQuestao(i,this));
    window->setFixedSize(ui->mdiArea->size());
    window->setWindowFlags(Qt::FramelessWindowHint);
    window->show();



}

PainelDeControle::~PainelDeControle()
{
    delete ui;
}


void PainelDeControle::on_actionCadastrarQuestao_triggered()
{
    auto window=ui->mdiArea->addSubWindow(new formCadastrarQuestao(ii,this));
    window->setFixedSize(ui->mdiArea->size());
    window->setWindowFlags(Qt::FramelessWindowHint);
    window->show();

}

void PainelDeControle::on_actionResponder_Quest_o_triggered()
{
    auto window=ui->mdiArea->addSubWindow(new ResponderQuestoes(ii,this));
    window->setFixedSize(ui->mdiArea->size());
    window->setWindowFlags(Qt::FramelessWindowHint);
    window->show();


}

void PainelDeControle::on_actionMostrar_Respostas_triggered()
{
    auto window=ui->mdiArea->addSubWindow(new FormMostrarRespostas(this));
    window->setFixedSize(ui->mdiArea->size());
    window->setWindowFlags(Qt::FramelessWindowHint);
    window->show();

}
