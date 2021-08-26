#include <typeinfo>
#include "catalogo.h"

Catalogo::Catalogo(){}

Catalogo::Catalogo(Vettore<DeepPtr<Prodotto>> _prodotto):prodotto(_prodotto){}

void Catalogo::aggiungiProdotto(const Prodotto& bev){
   for(Vettore<DeepPtr<Prodotto>>::Iteratore it = prodotto.begin(); it != prodotto.end(); it++){
       if((*it).get() == &bev)return;
   }
   //prodotto.push_back(DeepPtr<Prodotto>(&bev));
}

Vettore<DeepPtr<Prodotto>> Catalogo::listaProdotti()const{
    return prodotto;
}

Vettore<DeepPtr<Bevanda>> Catalogo::listaBevande()const{
    Vettore<DeepPtr<Bevanda>> aux;
    for(auto it = prodotto.begin(); it != prodotto.end(); it++){
        if(typeid (*(it->get())) == typeid (Bevanda) ){
            Bevanda *temp = dynamic_cast<Bevanda*>(it->get());
            aux.push_back(DeepPtr<Bevanda>(temp));
        }
    }
    return aux;
}
Vettore<DeepPtr<Cocktail>> Catalogo::listaCocktail()const{
    Vettore<DeepPtr<Cocktail>> aux;
    for(auto it = prodotto.begin(); it != prodotto.end(); it++){
        if(typeid (*(it->get())) == typeid (Cocktail) ){
            Cocktail *temp = dynamic_cast<Cocktail*>(it->get());
            aux.push_back(DeepPtr<Cocktail>(temp));
        }
    }
    return aux;
}
Vettore<DeepPtr<Cibo>> Catalogo::listaCibi()const{
    Vettore<DeepPtr<Cibo>> aux;
    for(auto it = prodotto.begin(); it != prodotto.end(); it++){
        if(typeid (*(it->get())) == typeid (Cibo) ){
            Cibo *temp = dynamic_cast<Cibo*>(it->get());
            aux.push_back(DeepPtr<Cibo>(temp));
        }
    }
    return aux;
}
/**
Vettore<Prodotto> trovaProdottoIngredienti(Vettore<DeepPtr<Prodotto>> _prodotti, Vettore<Ingrediente> ingredienti){
    for(Vettore<DeepPtr<Prodotto>>::Iteratore it_prod = _prodotti.begin();it_prod != _prodotti.end(); it_prod++){
        for(Vettore<Ingrediente>::Iteratore it_ing_prod = (*it_prod)->getIngredienti().begin();
            it_ing_prod != (*it_prod)->getIngredienti().end(); it_ing_prod++)
        {
            for(Vettore<Ingrediente>::Iteratore it_ing = ingredienti.begin(); it_ing != ingredienti.end(); it_ing++ ){

            }
        }
    }
}
*/

