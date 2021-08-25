#ifndef VIEW_H
#define VIEW_H

#include "home.h"
#include "carrello.h"
#include "alcolicopage.h"
#include "analcolicopage.h"
#include "ingredientpage.h"
#include "cocktailpage.h"
#include <QWidget>

class View : public QWidget{
   Q_OBJECT
private:
    Home* homepg = nullptr;
    Carrello* cartpg = nullptr;
    AlcolicoPage* alcolpg = nullptr;
    AnalcolicoPage* analcolpg = nullptr;
    IngredientPage* listpg = nullptr;
    CocktailPage* cocktailpg = nullptr;

public:
    explicit View();
    void hideCurrent();
public slots:
    void v_showCocktail();
    void v_showCarrello();
    void v_showAlcolico();
    void v_showAnalcolico();
    void v_showHome();
    void v_showIngredients();
};

#endif // VIEW_H
