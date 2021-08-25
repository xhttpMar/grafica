#include "home.h"
#include "view.h"
#include "header.h"
#include "carrello.h"
#include "alcolicopage.h"
#include "analcolicopage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    View* view = new View();
    view->show();
    return a.exec();
}
