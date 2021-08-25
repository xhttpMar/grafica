#ifndef CIBO_H
#define CIBO_H
#include "prodotto.h"
#include "ingrediente.h"
#include "vettore.h"
typedef unsigned int u_int;
class Cibo: public Prodotto{
    private:
        Vettore<Ingrediente> ingredienti;
    public:
        Cibo(string nome,u_int Quantita,Vettore<Ingrediente> Comp);
        bool operator ==(const Prodotto &second)const override;
        Vettore<Ingrediente> getIngredienti()const override;

        Vettore<Ingrediente> calcolaIngredienti(const u_int )const override;
        Cibo* clone() const override;
};

#endif // CIBO_H
