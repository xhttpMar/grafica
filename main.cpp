#include "view/home.h"
#include "view.h"
#include "view/header.h"
#include "view/carrellopage.h"
#include "view/alcolicopage.h"
#include "view/analcolicopage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    View* view = new View();
    view->show();
    return a.exec();
}
