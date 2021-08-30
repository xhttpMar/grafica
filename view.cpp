#include "view.h"
#include "controller.h"

View::View(Controller* ctr):_controller(ctr){
    homepg  = new Home(this);
    homepg->show();
    connect(homepg, &Home::toCocktailPage, this, &View::v_showCocktail);
    connect(homepg, &Home::toAlcolicoPage, this, &View::v_showAlcolico);
    connect(homepg, &Home::toAnalcolicoPage, this, &View::v_showAnalcolico);
    connect(homepg, &Home::toCarrelloPage, this, &View::v_showCarrello);
    setWindowIcon(QIcon(":/icon/bar.png"));
}

void View::hideCurrent(){
    if(homepg && homepg->isVisible()) {
        homepg->hide();
    }
    else if(analcolpg && analcolpg->isVisible()){
        analcolpg->hide();
    }
    else if(alcolpg && alcolpg->isVisible()){
        alcolpg->hide();
    }
    else if(listpg && listpg->isVisible()){
        listpg->hide();
    }
    else if(cartpg && cartpg->isVisible()){
        cartpg->hide();
    }
    else if(cocktailpg && cocktailpg->isVisible()){
        cocktailpg->hide();
    }
}

void View::v_showCocktail(){
    hideCurrent();
    if(!cocktailpg) cocktailpg=new CocktailPage(this, _controller->getVettoreProdotti().listaCocktail());
    resize(1080,920);
    move(QPoint(400,20));
    setMinimumSize(1080,920);
    setMaximumSize(1080,920);
    cocktailpg->show();
    connect(cocktailpg, &CocktailPage::toHomePage, this, &View::v_showHome);
    connect(cocktailpg, &CocktailPage::toCarrelloPage, this, &View::v_showCarrello);
    //connect(cocktailpg, &CocktailPage::sendAddRequestToController, &Controller::c_addToCart);
    connect(cocktailpg, SIGNAL(sendAddRequestToController(Cocktail*, int)), this, SLOT(c_addToCart(Cocktail*, int)) );
}

void View::v_showCarrello(){
    hideCurrent();
    cartpg = new Carrellopage(this, _controller->getCarrello().getProdotti());
    resize(1080,920);
    move(QPoint(400,20));
    setMinimumSize(1080,920);
    setMaximumSize(1080,920);
    cartpg->show();
    connect(cartpg, &Carrellopage::toHomePage, this, &View::v_showHome);
    connect(cartpg, &Carrellopage::toIngredientsPage, this, &View::v_showIngredients);
}

void View::v_showAlcolico(){
    hideCurrent();
    if(!alcolpg) alcolpg = new AlcolicoPage(this, _controller->getVettoreProdotti().listaAlcolici());
    resize(1080,920);
    move(QPoint(400,20));
    setMinimumSize(1080,920);
    setMaximumSize(1080,920);
    alcolpg->show();
    //per tornare indietro
    connect(alcolpg, &AlcolicoPage::toHomePage, this, &View::v_showHome);
    connect(alcolpg, &AlcolicoPage::toCarrelloPage, this, &View::v_showCarrello);
}

void View::v_showAnalcolico(){
    hideCurrent();
    if(!analcolpg) analcolpg = new AnalcolicoPage(this,_controller->getVettoreProdotti().listaAnalcolici());
    resize(1080,920);
    move(QPoint(400,20));
    setMinimumSize(1080,920);
    setMaximumSize(1080,920);
    analcolpg->show();
    //per tornare indietro
    connect(analcolpg, &AnalcolicoPage::toHomePage, this, &View::v_showHome);
    connect(analcolpg, &AnalcolicoPage::toCarrelloPage, this, &View::v_showCarrello);
}

void View::v_showHome(){
    hideCurrent();
    resize(680,260);
    setMinimumSize(680,260);
    setMaximumSize(680,260);
    move(QPoint(600,280));
    homepg->show();
}

void View::v_showIngredients(){
    hideCurrent();
    listpg = new IngredientPage(this);
    listpg->show();
    connect(listpg, &IngredientPage::toCarrelloPage, this, &View::v_showCarrello);
    connect(listpg, &IngredientPage::toHomePage, this, &View::v_showHome);
}
