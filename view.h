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

class View : public QWidget{
   Q_OBJECT
private:
    Home* homepg = nullptr;
    Carrellopage* cartpg = nullptr;
    AlcolicoPage* alcolpg = nullptr;
    AnalcolicoPage* analcolpg = nullptr;
    IngredientPage* listpg = nullptr;
    CocktailPage* cocktailpg = nullptr;
    Catalogo catalogo;
public:
    explicit View(Catalogo cat);
    void hideCurrent();
    Catalogo getCatalogo() {return catalogo;}
public slots:
    void v_showCocktail();
    void v_showCarrello();
    void v_showAlcolico();
    void v_showAnalcolico();
    void v_showHome();
    void v_showIngredients();
};

#endif // VIEW_H
