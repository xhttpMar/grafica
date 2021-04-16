#include "listaOggetti.h"
#include "home.h"
#include <QObject>

listaOggetti::listaOggetti(QWidget *parent) : QWidget(parent){
    QListWidget* lw = new QListWidget;
    //QObject::connect(ret->actions()[0], SIGNAL(triggered()),this, SLOT(handleManu()));
    QListWidgetItem* lwi = new QListWidgetItem;
    lw->addItem(lwi);
    for (int var = 0; var < 10; ++var)
    {
        QWidget* w = new QWidget();
        QVBoxLayout* princ = new QVBoxLayout(w);
        QHBoxLayout* fotoNome = new QHBoxLayout;
            QImage* image = new QImage("C:/Users/marts/Desktop/m3.jpg");
            QLabel* provaim = new QLabel("");
            provaim->setPixmap(QPixmap::fromImage(*image));
            QVBoxLayout* nomegrad = new QVBoxLayout;
            QLabel* nome = new QLabel("Mojito");
            QLabel* grad = new QLabel("gradazione: ");
            nomegrad->addWidget(nome);
            nomegrad->addWidget(grad);
            fotoNome->addWidget(provaim);
            fotoNome->addLayout(nomegrad);
        QVBoxLayout* desc = new QVBoxLayout;
            QLabel* descr = new QLabel("Descrizione:");
            QPushButton* add = new QPushButton("Add");
            desc->addWidget(descr);
            desc->addWidget(add);
        princ->addLayout(fotoNome);
        princ->addLayout(desc);
        QListWidgetItem* lwi = new QListWidgetItem;
        lwi->setSizeHint( w->sizeHint() );
        lw->addItem(lwi);
        lw->setItemWidget(lwi, w);
    }
    lw->show();
}

