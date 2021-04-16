#include "home.h"
#include "listaOggetti.h"
#include <carrello.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Home h;
    h.show();
    return a.exec();
}
