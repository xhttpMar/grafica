#include <iostream>
#include<typeinfo>
#include "cocktail.h"

Cocktail::Cocktail(string Nome, u_int Quantita, Vettore<Ingrediente> ing,  u_int Gradazione) :
    Bevanda(Nome,Quantita,Gradazione), ingredienti(ing)
{
    for(auto it=ing.begin(); it!=ing.end(); it++){
        ingredienti.push_back(*it);
    }

}

Vettore<Ingrediente> Cocktail::getIngredienti() const{
    return ingredienti;
}

bool Cocktail::verificaIngredienti(Vettore<Ingrediente> ingr)const{
    bool chk = false;
    for(auto it = ingredienti.begin(); it != ingredienti.end(); it++){
        chk = false;
        for(auto iter = ingr.begin(); !chk && iter != ingr.end(); iter++){
            if( *it == *iter ) chk = true;
        }
    }
    return chk;
}

bool Cocktail::operator ==(const Prodotto &second)const{
    return Bevanda::operator==(second) && ingredienti == static_cast<const Cocktail&>(second).ingredienti;
}
Vettore<Ingrediente> Cocktail::calcolaIngredienti(const u_int litri) const{
    Vettore<Ingrediente> aux;
    for(Ingrediente ingr : ingredienti){
        aux.push_back(ingr*(ingr.getQuantita()*(litri/quantita)));
    }
    return aux;
}

Cocktail* Cocktail::clone() const{
    return new Cocktail(*this);
}
