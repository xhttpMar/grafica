#include "home.h"

Home::Home(QWidget *parent) : QWidget(parent){
    QVBoxLayout* princ = new QVBoxLayout(this);
    this->setMinimumSize(560,560);

    QPushButton *listaOggetti = new QPushButton("Cerca");
    QLineEdit *barraCerca = new QLineEdit;
    barraCerca->setPlaceholderText("Cerca...");
    barraCerca->setBaseSize(10,150);
    QHBoxLayout *top = new QHBoxLayout;
    top->addWidget(barraCerca);
    top->addWidget(listaOggetti);
    princ->addLayout(top);

    QTabWidget* schede = new QTabWidget;
    QWidget* tutti = new QWidget;
    QWidget* alcolici = new QWidget;
    QWidget* analcolici = new QWidget;;
    schede->addTab(tutti, "Tutti");
    schede->addTab(alcolici, "Alcolici");
    schede->addTab(analcolici, "Analcolici");

    QListWidget* lista1 = new QListWidget(tutti);
    lista1->resize(550,550);
    QListWidgetItem* lwi = new QListWidgetItem;
    lista1->addItem(lwi);
    for (int var = 0; var < 10; ++var)
    {
        QFrame* fr = new QFrame(lista1);
        fr->adjustSize();
        fr->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        QVBoxLayout* princ = new QVBoxLayout(fr);
        QHBoxLayout* fotoNome = new QHBoxLayout;
            QImage* image = new QImage("D:/Marta/univeristà/secondo anno/PROGETTO/grafica/m3.jpg");
            QLabel* provaim = new QLabel("");
            provaim->setPixmap(QPixmap::fromImage(*image));
            QVBoxLayout* nomegrad = new QVBoxLayout;
            QLabel* nome = new QLabel("Mojito " + QString::number(var));
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
        lwi->setSizeHint( fr->sizeHint() );
        lista1->addItem(lwi);
        lista1->setItemWidget(lwi, fr);
    }

    QListWidget* lista3 = new QListWidget(alcolici);
    QListWidgetItem* lwi3 = new QListWidgetItem;
    lista3->resize(550,550);
    lista3->addItem(lwi3);
    for (int var = 0; var < 10; ++var)
    {
        QFrame* fr = new QFrame(lista3);
        QVBoxLayout* princ = new QVBoxLayout(fr);
        QHBoxLayout* fotoNome = new QHBoxLayout;
            QImage* image = new QImage("D:/Marta/univeristà/secondo anno/PROGETTO/grafica/birra.png");
            QLabel* provaim = new QLabel("");
            provaim->setPixmap(QPixmap::fromImage(*image));
            QVBoxLayout* nomegrad = new QVBoxLayout;
            QLabel* nome = new QLabel("Birra " + QString::number(var));
            QLabel* grad = new QLabel("gradazione:");
            nomegrad->addWidget(nome);
            nomegrad->addWidget(grad);
            fotoNome->addWidget(provaim);
            fotoNome->addLayout(nomegrad);
        QVBoxLayout* desc = new QVBoxLayout;
            QLabel* descr = new QLabel("Descrizione: ");
            QPushButton* add = new QPushButton("Add");
            desc->addWidget(descr);
            desc->addWidget(add);
        princ->addLayout(fotoNome);
        princ->addLayout(desc);
        QListWidgetItem* lwi3 = new QListWidgetItem;
        lwi3->setSizeHint(lista3->sizeHint());
        lwi3->setSizeHint( fr->sizeHint() );
        lista3->addItem(lwi);
        lista3->setItemWidget(lwi3, fr);
    }

    QListWidget* lista2 = new QListWidget(analcolici);
    lista2->resize(550,550);
    QListWidgetItem* lwi2 = new QListWidgetItem;
    lista2->addItem(lwi2);
    for (int var = 0; var < 10; ++var)
    {
        QFrame* fr = new QFrame(lista2);
        fr->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
        QVBoxLayout* princ = new QVBoxLayout(fr);
        QHBoxLayout* fotoNome = new QHBoxLayout;
            QImage* image = new QImage("D:/Marta/univeristà/secondo anno/PROGETTO/grafica/coca1.png");
            QLabel* provaim = new QLabel("");
            provaim->setPixmap(QPixmap::fromImage(*image));
            QVBoxLayout* nomegrad = new QVBoxLayout;
            QLabel* nome = new QLabel("Coca Cola " + QString::number(var));
            QLabel* grad = new QLabel("gradazione: NON DISPONIBILE");
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
        QListWidgetItem* lwi2 = new QListWidgetItem;
        lwi2->setSizeHint( fr->sizeHint() );
        lista2->addItem(lwi2);
        lista2->setItemWidget(lwi2, fr);
    }

    /*QHBoxLayout* schedaTutti = new QHBoxLayout(tutti); //layout con list
    QListWidget *lista1 = new QListWidget;
    for(int i=0; i<20; i++){
        QListWidgetItem* item = new QListWidgetItem(lista1);
        item->setText("prova " + QString::number(i));
        lista1->addItem(item);
    }
    schedaTutti->addWidget(lista1);

    QHBoxLayout* schedaAlcolici = new QHBoxLayout(alcolici);
    QListWidget *lista2 = new QListWidget;
    for(int i=0; i<20; i++){
        QListWidgetItem* item = new QListWidgetItem(lista2);
        item->setText("prova " + QString::number(i));
        lista2->addItem(item);
    }
    schedaAlcolici->addWidget(lista2);

    QHBoxLayout* schedaAnalcolici = new QHBoxLayout(analcolici);
    QListWidget *lista3 = new QListWidget;
    for(int i=0; i<20; i++){
        QListWidgetItem* item = new QListWidgetItem(lista3);
        item->setText("prova " + QString::number(i));
        lista2->addItem(item);
    }
    schedaAnalcolici->addWidget(lista3);
    */

    princ->addWidget(schede);
}
