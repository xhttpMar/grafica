#include <QApplication>
#include <iostream>

#include "view.h"
#include "model.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ingrediente ingr = Ingrediente("zucchero", 300, false);
    Prodotto* cocktail = new Cocktail("Mojito", 150, ingr, 23);
    Prodotto* cocktail2 = new Cocktail("Caipiroska", 150, ingr, 34);
    Prodotto* cocktail3 = new Cocktail("Gin basil", 150, ingr);
    Prodotto* cocktail4 = new Cocktail("Black russian", 150, ingr, 25);
    Prodotto* ciao = new Bevanda("coca cola", 50, 0);
    Catalogo cat;
    cat.aggiungiProdotto(*cocktail);
    cat.aggiungiProdotto(*cocktail2);
    cat.aggiungiProdotto(*cocktail3);
    cat.aggiungiProdotto(*cocktail4);
    cat.aggiungiProdotto(*ciao);
    Model model(cat);
    Controller controller(&model);
    View* view = new View(&controller);
    view->show();
    return a.exec();
}
