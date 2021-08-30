#include "controller.h"

Controller::Controller(Model* modello):_model(modello), _view(nullptr){}

void Controller::setView(View* view){
    _view = view;

    //connect tutte le cose
}

const Catalogo& Controller::getVettoreProdotti() const{
    return _model->getCatalogo();
}

const Carrello &Controller::getCarrello() const{
    return _model->getCarrello();
}

void Controller::c_addToCart(Cocktail* cocktail, int q){
    _model->aggiungiProdottoCarrello(*cocktail,q);
}
