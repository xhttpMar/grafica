#ifndef CARRELLO_H
#define CARRELLO_H
#include<iostream>
#include"vettore.h"
#include"ingrediente.h"
#include"prodotto.h"
#include "deepptr.h"
#include "bevanda.h"

typedef unsigned int u_int;

class Carrello
{
private:


    Vettore<std::pair<DeepPtr<Prodotto>,u_int>> prodotti;


public:
    Carrello();
    Vettore<Ingrediente> calcolaIngredienti()const;
    Vettore<DeepPtr<Prodotto>> getProdotti()const;
    u_int litriTot() const;
    void aggiungiProdotto(const Prodotto& bev,int Quantita);
    void removeProdotto(const Prodotto& bev);
    u_int gradazioneMedia();
    bool verificaIngredienti(const Prodotto& b);
};

#endif // CARRELLO_H
