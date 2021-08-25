#include <typeinfo>
#include "prodotto.h"

Prodotto::Prodotto(string Nome,u_int Quantita): nome(Nome), quantita(Quantita){}

Prodotto::~Prodotto(){}


bool Prodotto::operator ==(const Prodotto& second)const{
    return typeid (*this) == typeid (second) && nome == second.nome && quantita == second.quantita;
}
