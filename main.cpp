#include "view/home.h"
#include "view.h"
#include "view/header.h"
#include "view/carrellopage.h"
#include "view/alcolicopage.h"
#include "view/analcolicopage.h"

#include "model/catalogo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Vettore<DeepPtr<Prodotto>> lista;
    Bevanda* prima = new Bevanda("ciao", 7, 0);
    Prodotto* seconda = new Bevanda("ciao3", 10, 0);
    Prodotto* prodotto = new Bevanda("spritz",100,10);
    Vettore<Ingrediente> ingr(Ingrediente("rum",100,true));
    Prodotto* pr2 = new Cocktail("rum",100, ingr);
    Prodotto* pr3 = new Cocktail("vodka",100,ingr);
    Prodotto* pr4 = new Cocktail("gin",100,ingr);
    Prodotto* pr5 = new Cocktail("ciao",100,ingr);
    Catalogo* cat = new Catalogo();
    cat->aggiungiProdotto(*prima);
    cat->aggiungiProdotto(*seconda);
    cat->aggiungiProdotto(*prodotto);
    cat->aggiungiProdotto(*pr2);
    cat->aggiungiProdotto(*pr2);
    cat->aggiungiProdotto(*pr3);
    cat->aggiungiProdotto(*pr4);
    cat->aggiungiProdotto(*pr5);
    View* view = new View(*cat);
    view->show();
    return a.exec();
}
