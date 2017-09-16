#include "paineldecontrole.h"
#include <QApplication>
#include "formlogin.h"
#include <locale.h>

int main(int argc, char *argv[])
{

    setlocale(LC_ALL, "");
    QApplication a(argc, argv);

    formLogin w;
    w.show();
    return a.exec();


}
