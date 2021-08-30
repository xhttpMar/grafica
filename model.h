#ifndef MODEL_H
#define MODEL_H

#include "model/carrello.h"
#include "model/catalogo.h"

class Model{

private:
    Catalogo catalogo;
    Carrello carrello;
public:
    Model(Catalogo cat = Catalogo());
    ~Model();
    //Catalogo getCatalogo();
    const Catalogo& getCatalogo() const;
    const Carrello& getCarrello() const;
    void aggiungiProdottoCatalogo(const Prodotto& prodotto);
    void aggiungiProdottoCarrello(const Prodotto& prodotto, int quantita);
};

#endif // MODEL_H
