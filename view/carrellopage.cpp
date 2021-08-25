#include "carrellopage.h"

Carrellopage::Carrellopage(QWidget *parent) : QWidget(parent){
    container = new QVBoxLayout(this);
    addCart();
    connect(back, &QPushButton::clicked, this, &Carrellopage::showHomePage);
    connect(switchToList, &QPushButton::clicked, this, &Carrellopage::showIngredientsPage);
}

void Carrellopage::addCart(){
    this->setMinimumSize(1080,920);
    QLabel* title = new QLabel("Carrello");
    title->setFont(QFont("Verdana", 20));

    back = new QPushButton();
    switchToList = new QPushButton();
    QPixmap turnBackImg = QPixmap(":/icons/home.png");
    QPixmap turnSwitchImg = QPixmap(":/icons/to-do-list.png");
    back->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    back->setIcon(turnBackImg);
    back->setIconSize(QSize(50,50));
    back->resize(QSize(50,50));
    switchToList->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    switchToList->setIcon(turnSwitchImg);
    switchToList->setIconSize(QSize(50,50));
    switchToList->resize(QSize(50,50));
    QWidget* header = new Header(back, title, switchToList);

    QListWidget* cart = new QListWidget(this);
    cart->resize(this->size());
    cart->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    QListWidgetItem* item = new QListWidgetItem;
    cart->addItem(item);
    for(int i =0; i<15; i++){
        QWidget* w= new QWidget;
        w->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        QHBoxLayout* oggettoLista = new QHBoxLayout(w);

        //immagine cocktail
        QPushButton* plotImg = new QPushButton();
        QPixmap cocktailImg = QPixmap(":/icons/default.png");
        plotImg->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
        plotImg->setIcon(cocktailImg);
        plotImg->setIconSize(QSize(100,100));
        plotImg->resize(QSize(100,100));

        //nome cocktail
        QLabel* nome = new QLabel("Nome");
        nome->setStyleSheet("font-size: 24px;");

        //remove button
        remove = new QPushButton("Rimuovi");
        remove->setStyleSheet("font-size: 20px;");
        remove->resize(25,60);
        oggettoLista->addWidget(plotImg);
        oggettoLista->addWidget(nome);
        oggettoLista->addWidget(remove);
        oggettoLista->setAlignment(plotImg, Qt::AlignLeft);
        QListWidgetItem* item = new QListWidgetItem;
        item->setSizeHint(cart->sizeHint());
        cart->addItem(item);
        cart->setItemWidget(item, w);
        oggettoLista->setContentsMargins(15,15,15,15);
    }

    container->addWidget(header);
    container->addWidget(cart);
}

void Carrellopage::showHomePage(){
    emit toHomePage();
}

void Carrellopage::showIngredientsPage(){
    emit toIngredientsPage();
}
