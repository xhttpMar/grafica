#ifndef CATALOGO_H
#define CATALOGO_H
#include"vettore.h"
#include"prodotto.h"
#include "deepptr.h"
#include "ingrediente.h"
#include "bevanda.h"
#include "cocktail.h"
#include "cibo.h"
class Catalogo
{
private:
     Vettore<DeepPtr<Prodotto>> prodotto;
public:
    Catalogo();
    Catalogo(Vettore<DeepPtr<Prodotto>> _prodotto);
    void aggiungiProdotto(const Prodotto& bev);
    Vettore<DeepPtr<Prodotto>> listaProdotti()const;
    Vettore<DeepPtr<Bevanda>> listaBevande()const;
    Vettore<DeepPtr<Bevanda>> listaAnalcolici()const;
    Vettore<DeepPtr<Bevanda>> listaAlcolici()const;
    Vettore<DeepPtr<Cocktail>> listaCocktail()const;
    Vettore<DeepPtr<Cibo>> listaCibi()const;
   // Vettore<Prodotto> trovaProdottoIngredienti(Vettore<DeepPtr<Prodotto>> _prodotti, Vettore<Ingrediente> ingredienti);


};

#endif // CATALOGO_H
