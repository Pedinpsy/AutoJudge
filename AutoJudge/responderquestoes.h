#ifndef RESPONDERQUESTOES_H
#define RESPONDERQUESTOES_H

#include <QWidget>
#include <QModelIndex>

namespace Ui {
class ResponderQuestoes;
}

class ResponderQuestoes : public QWidget
{
    Q_OBJECT

public:
    explicit ResponderQuestoes(QString c, QWidget *parent = 0);
    ~ResponderQuestoes();

private slots:
    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::ResponderQuestoes *ui;
};

#endif // RESPONDERQUESTOES_H
