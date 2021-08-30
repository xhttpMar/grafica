#ifndef VIEW_H
#define VIEW_H

#include "view/home.h"
#include "view/carrellopage.h"
#include "view/alcolicopage.h"
#include "view/analcolicopage.h"
#include "view/ingredientpage.h"
#include "view/cocktailpage.h"
#include "model/catalogo.h"
#include <QWidget>

class Controller;
class Catalogo;
class Home;
class Carrellopage;

class View : public QWidget{
   Q_OBJECT
private:
    Controller* _controller;

    Home* homepg = nullptr;
    Carrellopage* cartpg = nullptr;
    AlcolicoPage* alcolpg = nullptr;
    AnalcolicoPage* analcolpg = nullptr;
    IngredientPage* listpg = nullptr;
    CocktailPage* cocktailpg = nullptr;

public:
    explicit View(Controller* controller);
    void hideCurrent();
    const Catalogo& getCatalogo() const;
public slots:
    void v_showCocktail();
    void v_showCarrello();
    void v_showAlcolico();
    void v_showAnalcolico();
    void v_showHome();
    void v_showIngredients();
};

#endif // VIEW_H
