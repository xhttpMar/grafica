#ifndef PRODOTTO_H
#define PRODOTTO_H
#include <string>
#include "vettore.h"
#include "ingrediente.h"
using namespace std;
typedef unsigned int u_int;
class Prodotto
{
protected:
    std::string nome;
    u_int quantita;
public:
    Prodotto(string Nome,u_int Quantita);
    virtual ~Prodotto();
    virtual Vettore<Ingrediente> calcolaIngredienti(const u_int )const=0;
    virtual Vettore<Ingrediente> getIngredienti() const= 0;
    virtual Prodotto* clone() const = 0;
    virtual bool operator ==(const Prodotto&)const;
    virtual std::string getNome() const {return nome;}
};

#endif // PRODOTTO_H
