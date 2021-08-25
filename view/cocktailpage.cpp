#include "cocktailpage.h"

CocktailPage::CocktailPage(QWidget* parent): QWidget(parent){
    cocktailList = new QVBoxLayout(this);
    addItems();
    connect(back, &QPushButton::clicked, this, &CocktailPage::showHomePage);
    connect(cart, &QPushButton::clicked, this, &CocktailPage::showCarrelloPage);
}

void CocktailPage::addItems(){
    this->setMinimumSize(1080,920);
    QLabel* title = new QLabel("Cocktails");
    title->setFont(QFont("Verdana", 20));

    back = new QPushButton();
    cart = new QPushButton();
    QPixmap turnBackImg = QPixmap("C:/Users/marts/Desktop/home.png");
    QPixmap plotCartImg = QPixmap("C:/Users/marts/Desktop/iconcart.png");
    back->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    back->setIcon(turnBackImg);
    back->setIconSize(QSize(50,50));
    back->resize(QSize(50,50));
    cart->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    cart->setIcon(plotCartImg);
    cart->setIconSize(QSize(50,50));
    cart->resize(QSize(50,50));
    QWidget* header = new Header(back, title, cart);

    QListWidget* catalogue = new QListWidget(this);
    QListWidgetItem* entry = new QListWidgetItem;
    catalogue->addItem(entry);

    for(int i=0; i<20; i++){
        QWidget* w= new QWidget;

        QHBoxLayout* item = new QHBoxLayout(w);

        //immagine elemento
        QPushButton* plotImg = new QPushButton();
        QPixmap cocktailImg = QPixmap("C:/Users/marts/Desktop/cocktail.png");
        plotImg->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
        plotImg->setIcon(cocktailImg);
        plotImg->setIconSize(QSize(100,100));
        plotImg->resize(QSize(100,100));

        //nome analcolico
        QLabel* nome = new QLabel("Nome analcolico");
        nome->setStyleSheet("font-size: 24px;");

        //quantità
        QHBoxLayout* quant = new QHBoxLayout;
        QLabel* quantitaLabel = new QLabel("Quantità :");
        quantitaLabel->setStyleSheet("font-size: 24px;");
        quantity = new QSpinBox;
        quantity->setMaximum(99);
        quantity->setMinimum(0);
        quantity->setStyleSheet("font-size: 24px;");
        quant->addWidget(quantitaLabel);
        quant->addWidget(quantity);

        //addToCart button
        add = new QPushButton("Aggiungi al carrello");
        add->setStyleSheet("font: bold; font-size: 20px;");
        add->resize(25,60);
        item->addWidget(plotImg);
        item->addWidget(nome);
        item->addLayout(quant);
        item->addWidget(add);
        item->setAlignment(plotImg, Qt::AlignLeft);
        QListWidgetItem* oggetto = new QListWidgetItem;
        oggetto->setSizeHint(catalogue->sizeHint());
        catalogue->addItem(oggetto);
        catalogue->setItemWidget(oggetto, w);
        item->setContentsMargins(15,15,15,15);
    }

    cocktailList->addWidget(header);
    cocktailList->addWidget(catalogue);
}

void CocktailPage::showHomePage(){
    emit toHomePage();
}

void CocktailPage::showCarrelloPage(){
    emit toCarrelloPage();
}
