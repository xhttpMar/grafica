#include<typeinfo>
#include "cibo.h"
#include "ingrediente.h"
#include "vettore.h"

Cibo::Cibo(string Nome, u_int Quantita,Vettore<Ingrediente> Ing):Prodotto(Nome,Quantita), ingredienti(Ing){}


bool Cibo::operator ==(const Prodotto &second)const{
    return Prodotto::operator==(second) && ingredienti == static_cast<const Cibo&>(second).ingredienti;
}


Vettore<Ingrediente> Cibo::getIngredienti() const{
    return ingredienti;
}
Vettore<Ingrediente> Cibo::calcolaIngredienti(u_int quantita_r)const {
    Vettore<Ingrediente> aux;
    for(Ingrediente ing : ingredienti){
        aux.push_back(ing *(ing.getQuantita()*(quantita_r/quantita)));
    }
    return aux;
}
Cibo* Cibo::clone() const{
    return new Cibo(*this);
}
