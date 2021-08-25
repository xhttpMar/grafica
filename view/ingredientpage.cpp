#include "ingredientpage.h"

IngredientPage::IngredientPage(QWidget*parent): QWidget(parent){
    mainLayout = new QVBoxLayout(this);
    addList();
    connect(back, &QPushButton::clicked, this, &IngredientPage::showHomePage);
    connect(switchToCarrello, &QPushButton::clicked, this, &IngredientPage::showCarrelloPage);
}

void IngredientPage::addList(){
    this->setMinimumSize(1080,920);

    QLabel* title = new QLabel("Lista della spesa");
    title->setFont(QFont("Verdana", 20));

    back = new QPushButton();
    switchToCarrello = new QPushButton();
    QPixmap turnBackImg = QPixmap(":/icons/home.png");
    QPixmap SwitchImg = QPixmap(":/icons/iconcart.png");
    back->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    back->setIcon(turnBackImg);
    back->setIconSize(QSize(50,50));
    back->resize(QSize(50,50));
    switchToCarrello->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    switchToCarrello->setIcon(SwitchImg);
    switchToCarrello->setIconSize(QSize(50,50));
    switchToCarrello->resize(QSize(50,50));
    QWidget* header = new Header(back, title, switchToCarrello);

    QListWidget* cart = new QListWidget(this);
    cart->resize(this->size());
    cart->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    QListWidgetItem* item = new QListWidgetItem;
    cart->addItem(item);
    for(int i =0; i<15; i++){
        QWidget* w= new QWidget;
        w->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        QHBoxLayout* oggettoLista = new QHBoxLayout(w);

        //nome cocktail
        QLabel* nome = new QLabel("Nome ingrediente");
        nome->setStyleSheet("font-size: 24px;");

        QLabel* quantityLabel = new QLabel("Quantità: ");
        quantityLabel->setStyleSheet("font-size: 24px;");

        quantity = new QLabel("99");
        quantity->setStyleSheet("font-size: 24px;");

        oggettoLista->addWidget(nome);
        oggettoLista->addWidget(quantityLabel);
        oggettoLista->addWidget(quantity);

        QListWidgetItem* item = new QListWidgetItem;
        item->setSizeHint(cart->sizeHint());
        cart->addItem(item);
        cart->setItemWidget(item, w);
        oggettoLista->setContentsMargins(15,15,15,15);
    }

    mainLayout->addWidget(header);
    mainLayout->addWidget(cart);
}

void IngredientPage::showHomePage(){
    emit toHomePage();
}

void IngredientPage::showCarrelloPage(){
    emit toCarrelloPage();
}
