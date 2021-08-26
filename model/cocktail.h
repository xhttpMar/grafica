#ifndef COCKTAIL_H
#define COCKTAIL_H

#include<iostream>
#include "vettore.h"
#include "ingrediente.h"
#include "carrello.h"
#include "bevanda.h"

typedef unsigned int u_int;

class Cocktail : public Bevanda{
private:
    Vettore<Ingrediente> ingredienti;

public:
    Cocktail(string Nome, u_int Quantita,Vettore<Ingrediente> ing, u_int Grad=0);
     Vettore<Ingrediente> calcolaIngredienti(const u_int litri) const override;
    // virtual Vettore<Bevanda> crea(Carrello c /* ? Vettore<ingredienti> */);
     Vettore<Ingrediente> getIngredienti() const override;

    //in teoria non serve perchè lo eredita da Alcolico
    //virtual u_int getGradazione() const;

    bool verificaIngredienti(Vettore<Ingrediente> ingr) const override;
    bool operator ==(const Prodotto &second)const override;
    Cocktail* clone() const override;
};

#endif // COCKTAIL_H
