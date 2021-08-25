#include "bevanda.h"
#include<typeinfo>

Bevanda::Bevanda(string Nome,u_int Quantita, u_int Gradazione):Prodotto(Nome,Quantita), gradazione(Gradazione){}

Bevanda::Bevanda(const Bevanda& b):Prodotto(b.nome,b.quantita){
    gradazione=b.gradazione;
}

u_int Bevanda::getGradazione() const{
    return gradazione;
}

Vettore<Ingrediente> Bevanda::getIngredienti() const{
    return Vettore<Ingrediente>(Ingrediente(nome));
}

Vettore<Ingrediente> Bevanda::calcolaIngredienti(const u_int litri) const{
    return Vettore<Ingrediente>(Ingrediente(nome, litri));
}


bool Bevanda::verificaIngredienti(Vettore<Ingrediente> ingredienti)const{
    bool chk = false;
    for(auto it = ingredienti.begin(); !chk && it != ingredienti.end(); it++){
        if((*it).getNome()==nome) chk=true;
    }
    return chk ;
}

bool Bevanda::operator==(const Prodotto& second)const {
    return Prodotto::operator==(second) && gradazione == static_cast<const Bevanda&>(second).gradazione;
}

Bevanda* Bevanda::clone() const{
    return new Bevanda(*this);
}
