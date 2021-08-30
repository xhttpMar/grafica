#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include "model.h"
#include "view.h"

class View;

class Controller: public QObject {
    Q_OBJECT
public:
    Controller(Model* model);
    void setView(View* view);
    const Catalogo& getVettoreProdotti() const;
    const Carrello& getCarrello() const;
private:
    Model* _model;
    View* _view;

public slots:
    void c_addToCart(Cocktail* cocktail, int q);
signals:
    void sendAddToCartRequest(Cocktail* cocktail, int q);
};

#endif // CONTROLLER_H
