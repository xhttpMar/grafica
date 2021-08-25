#include "alcolicopage.h"

AlcolicoPage::AlcolicoPage(QWidget* parent): QWidget(parent){
    AlcolList = new QVBoxLayout(this);
    addItems();
    connect(back, &QPushButton::clicked, this, &AlcolicoPage::showHomePage);
    connect(cart, &QPushButton::clicked, this, &AlcolicoPage::showCarrelloPage);
}

void AlcolicoPage::addItems(){
    this->setMinimumSize(1080,920);
    QLabel* title = new QLabel("Bevande alcoliche");
    title->setFont(QFont("Verdana", 20));

    back = new QPushButton();
    cart = new QPushButton();
    QPixmap plotBackImg = QPixmap(":/icons/home.png");
    QPixmap plotCartImg = QPixmap(":/icons/iconcart.png");
    back->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    back->setIcon(plotBackImg);
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
        QPixmap cocktailImg = QPixmap(":/icons/beer.png");
        plotImg->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
        plotImg->setIcon(cocktailImg);
        plotImg->setIconSize(QSize(100,100));
        plotImg->resize(QSize(100,100));

        //nome alcolico
        QLabel* nome = new QLabel("Nome alcolico");
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

    AlcolList->addWidget(header);
    AlcolList->addWidget(catalogue);
}

void AlcolicoPage::showHomePage(){
    emit toHomePage();
}

void AlcolicoPage::showCarrelloPage(){
    emit toCarrelloPage();
}
