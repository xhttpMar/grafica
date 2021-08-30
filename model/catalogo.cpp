#include <typeinfo>
#include "catalogo.h"

Catalogo::Catalogo(){}

Catalogo::Catalogo(Vettore<DeepPtr<Prodotto>> _prodotto):prodotto(_prodotto){}

void Catalogo::aggiungiProdotto(const Prodotto& bev){
    if(prodotto.empty()){
        prodotto.push_back(bev.clone());
        return;
    }
    for(Vettore<DeepPtr<Prodotto>>::Iteratore it = prodotto.begin(); it != prodotto.end(); it++){
        if((*it).get() == &bev)return;
    }
    prodotto.push_back(bev.clone());
}

Vettore<DeepPtr<Prodotto>> Catalogo::listaProdotti()const{
    return prodotto;
}

Vettore<DeepPtr<Bevanda>> Catalogo::listaBevande()const{
    Vettore<DeepPtr<Bevanda>> aux;
    for(auto it = prodotto.cbegin(); it != prodotto.cend(); it++){
        Bevanda *temp = dynamic_cast<Bevanda*>(it->get());
        if(temp){
            aux.push_back(temp->clone());
        }
    }
    return aux;
}

Vettore<DeepPtr<Bevanda> > Catalogo::listaAnalcolici() const{
    Vettore<DeepPtr<Bevanda>> aux;
    for(auto it = prodotto.cbegin(); it != prodotto.cend(); it++){
        Bevanda *temp = dynamic_cast<Bevanda*>(it->get());
        if(temp && temp->getGradazione()==0){
            aux.push_back(temp->clone());
        }
    }
    return aux;
}

Vettore<DeepPtr<Bevanda> > Catalogo::listaAlcolici() const{
    Vettore<DeepPtr<Bevanda>> aux;
    for(auto it = prodotto.cbegin(); it != prodotto.cend(); it++){
        Bevanda *temp = dynamic_cast<Bevanda*>(it->get());
        if(temp && temp->getGradazione()>0){
            aux.push_back(temp->clone());
        }
    }
    return aux;
}

Vettore<DeepPtr<Cocktail>> Catalogo::listaCocktail()const{
    Vettore<DeepPtr<Cocktail>> aux;
    for(auto it = prodotto.cbegin(); it != prodotto.cend(); it++){
        Cocktail *temp = dynamic_cast<Cocktail*>(it->get());
        if(temp){
            aux.push_back(temp->clone());
        }
    }
    return aux;
}
Vettore<DeepPtr<Cibo>> Catalogo::listaCibi()const{
    Vettore<DeepPtr<Cibo>> aux;
    for(auto it = prodotto.cbegin(); it != prodotto.cend(); it++){
        Cibo *temp = dynamic_cast<Cibo*>(it->get());
        if(temp){
            aux.push_back(temp->clone());
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

