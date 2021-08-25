#include "home.h"
#include "header.h"

Home::Home(QWidget *parent) : QWidget(parent){
    LayoutMain=new QVBoxLayout(this);
    addProducts();
    //setLayout(LayoutMain);
    connect(cocktails, &QPushButton::clicked, this, &Home::showCocktailPage);
    connect(analcolici, &QPushButton::clicked, this, &Home::showAnalcolicoPage);
    connect(alcolici, &QPushButton::clicked, this, &Home::showAlcolicoPage);
    connect(carrello, &QPushButton::clicked, this, &Home::showCarrelloPage);
}

void Home::addProducts(){
    QLabel* welcome = new QLabel("Benvenuto su DrinkITHome");
    welcome->setFont(QFont("Verdana", 20));
    welcome->setAlignment(Qt::AlignCenter);
    QLabel* titolo = new QLabel("Seleziona il servizio:");
    titolo->setFont(QFont("Verdana", 14));
    titolo->setAlignment(Qt::AlignCenter);

    ProdottiLayout = new QHBoxLayout();
    ProdottiLayout->setAlignment(Qt::AlignCenter);
    cocktails = new QPushButton();
    alcolici = new QPushButton();
    analcolici = new QPushButton();
    carrello = new QPushButton();

    //pulsante cocktails
    QPixmap cocktailsIcon = QPixmap(":/icons/cocktail.png");
    cocktails->setIcon(cocktailsIcon);
    cocktails->setIconSize(QSize(150,150));
    cocktails->resize(QSize(150,150));
    cocktails->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    cocktails->setStyleSheet("border:3px solid #e0e0e0;");
    QPalette pal1 = cocktails->palette();
    pal1.setColor(QPalette::Button, QColor(Qt::white));
    cocktails->setAutoFillBackground(true);
    cocktails->setPalette(pal1);
    cocktails->update();

    //pulsante analcolici
    QPixmap analcoliciIcon = QPixmap(":/icons/softdrinks.png");
    analcolici->setIcon(analcoliciIcon);
    analcolici->setIconSize(QSize(150,150));
    analcolici->resize(QSize(150,150));
    analcolici->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    analcolici->setStyleSheet("border:3px solid #e0e0e0;");
    QPalette pal2 = analcolici->palette();
    pal2.setColor(QPalette::Button, QColor(Qt::white));
    analcolici->setAutoFillBackground(true);
    analcolici->setPalette(pal2);
    analcolici->update();

    //pulsante alcolici
    QPixmap alcoliciIcon = QPixmap(":/icons/beer.png");
    alcolici->setIcon(alcoliciIcon);
    alcolici->setIconSize(QSize(150,150));
    alcolici->resize(QSize(150,150));
    alcolici->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    alcolici->setStyleSheet("border:3px solid #e0e0e0;");
    QPalette pal3 = alcolici->palette();
    pal3.setColor(QPalette::Button, QColor(Qt::white));
    alcolici->setAutoFillBackground(true);
    alcolici->setPalette(pal3);
    alcolici->update();

    //pulsante carrello
    QPixmap carrelloIcon = QPixmap(":/icons/shopping-cart.png");
    carrello->setIcon(carrelloIcon);
    carrello->setIconSize(QSize(150,150));
    carrello->resize(QSize(150,150));
    carrello->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    carrello->setStyleSheet("border:3px solid #e0e0e0;");
    QPalette pal5 = carrello->palette();
    pal5.setColor(QPalette::Button, QColor(Qt::white));
    carrello->setAutoFillBackground(true);
    carrello->setPalette(pal5);
    carrello->update();

    //aggiungi pulsanti
    ProdottiLayout->addWidget(cocktails);
    ProdottiLayout->addWidget(analcolici);
    ProdottiLayout->addWidget(alcolici);
    ProdottiLayout->addWidget(carrello);

    //layout principale
    LayoutMain->addWidget(welcome);
    LayoutMain->addWidget(titolo);
    LayoutMain->addLayout(ProdottiLayout);
}

void Home::showCocktailPage(){
    emit toCocktailPage();
}

void Home::showAlcolicoPage(){
    emit toAlcolicoPage();
}

void Home::showAnalcolicoPage(){
    emit toAnalcolicoPage();
}

void Home::showCarrelloPage(){
    emit toCarrelloPage();
}

