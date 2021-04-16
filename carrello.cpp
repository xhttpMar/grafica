#include "carrello.h"


Carrello::Carrello(QWidget *parent) : QWidget(parent){
    QWidget* princ = new QWidget;
    princ->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    princ->setMinimumSize(1080,920);
    QListWidget* chart = new QListWidget(princ);
    chart->resize(princ->size());
    chart->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    QListWidgetItem* item = new QListWidgetItem;
    chart->addItem(item);
    for(int i =0; i<15; i++){
        QWidget* w= new QWidget;
        w->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        QVBoxLayout* skel = new QVBoxLayout(w);
        QLabel* nome = new QLabel("Nome cocktail");
        nome->resize(720,500);
        QHBoxLayout* quant = new QHBoxLayout;
            QLabel* quantita = new QLabel("Quantità :");
            QSpinBox* spin = new QSpinBox;
            spin->setMaximum(99);
            spin->setMinimum(0);
            quant->addWidget(quantita);
            quant->addWidget(spin);
        QPushButton* remove = new QPushButton("Rimuovi");
        remove->setStyleSheet("font: bold; background-color: pink; fot-size: 24px;");
        remove->resize(25,60);
        skel->addWidget(nome);
        skel->addLayout(quant);
        skel->addWidget(remove);
        QListWidgetItem* item = new QListWidgetItem;
        item->setSizeHint(chart->sizeHint());
        chart->addItem(item);
        chart->setItemWidget(item, w);
        skel->setContentsMargins(15,15,15,15);

    }

    princ->show();
}
