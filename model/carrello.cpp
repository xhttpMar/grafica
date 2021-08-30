#include "carrello.h"
#include "prodotto.h"
#include "ingrediente.h"
#include "cibo.h"
#include "bevanda.h"

Carrello::Carrello() {}

Vettore<Ingrediente> Carrello::calcolaIngredienti()const{
    Vettore<Ingrediente> aux;
    for(auto it=prodotti.cbegin(); it!=prodotti.cend(); it++){
    //for(std::pair<DeepPtr<Prodotto>,u_int> __prodotto : prodotti){
        if(dynamic_cast<Bevanda*>(it->first.get())){
            const Bevanda* bevanda= static_cast<const Bevanda*>(it->first.get());
            Vettore<Ingrediente> temp(bevanda->calcolaIngredienti(it->second));
            aux.merge(temp);
        }
    }
    return aux;
}


/*Vettore<DeepPtr<Prodotto>> Carrello::getProdotti()const{
    Vettore<DeepPtr<Prodotto>> aux;
    for(auto it=prodotti.cbegin(); it!=prodotti.cend(); it++){
    //for(std::pair<DeepPtr<Prodotto>,u_int> punt : prodotti){
        aux.push_back(it->first);
    }
    return aux;
}*/

Vettore<std::pair<DeepPtr<Prodotto>,u_int>> Carrello::getProdotti()const{
    return prodotti;
}

u_int Carrello::litriTot() const{
    u_int totale = 0;
    for(auto it=prodotti.cbegin(); it!=prodotti.cend(); it++){
    //for(std::pair<DeepPtr<Prodotto>,u_int> __prodotto : prodotti){
        if(dynamic_cast<Bevanda*>(it->first.get())){
           totale += it->second;
        }
    }
    return totale;

}

void Carrello::aggiungiProdotto(const Prodotto& bev,int Quantita){
    bool non_trovato = true;
    for(Vettore<pair<DeepPtr<Prodotto>,u_int>>::Iteratore it = prodotti.begin(); non_trovato && it!=prodotti.end(); it++ ){
        if(it->first.get() == &bev){
            (*it).second += Quantita;
            non_trovato=false;
        }
    }
    if(non_trovato)prodotti.push_back(std::pair<DeepPtr<Prodotto>,u_int>(bev.clone(),Quantita));
}

u_int Carrello::gradazioneMedia(){
    u_int gradazione=0, tot_quantita=0;
    for(std::pair<DeepPtr<Prodotto>,u_int> __prodotto : prodotti){
        if(dynamic_cast<Bevanda*>(__prodotto.first.get())){
            Bevanda* bevanda = static_cast<Bevanda*>(__prodotto.first.get());
            gradazione += bevanda->getGradazione()*__prodotto.second;
            tot_quantita += __prodotto.second;
        }

    }
    return tot_quantita ? gradazione/tot_quantita : 0;
}



bool Carrello::verificaIngredienti(const Prodotto& b){
    Vettore<Ingrediente> ingredienti = calcolaIngredienti(), b_ingredienti = b.getIngredienti();
    for(Vettore<Ingrediente>::Iteratore it = ingredienti.begin(); it != ingredienti.end(); it++){
        for(Vettore<Ingrediente>::Iteratore it_b = b.getIngredienti().begin(); it_b != b.getIngredienti().end(); it_b++){
            if(*it == *it_b){
                b_ingredienti.remove(it_b);
                it_b = b.getIngredienti().end();
            }
        }
    }
    if(b_ingredienti.empty())return true;
    else {
        return false;
    }
}























