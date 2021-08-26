#ifndef COCKTAILPAGE_H
#define COCKTAILPAGE_H

#include "view/header.h"
#include "model/vettore.h"
#include "model/cocktail.h"
#include "model/deepptr.h"

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>
#include <QLabel>
#include <QSpinBox>
#include <QListWidget>
#include <QString>

class CocktailPage: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* cocktailList;
    QPushButton* back;
    QPushButton* cart;
    QPushButton* add;
    QSpinBox* quantity;
    Vettore<DeepPtr<Cocktail>> lista;
public:
    explicit CocktailPage(QWidget* parent, Vettore<DeepPtr<Cocktail>> vec_coc);
    void addItems();
signals:
    void toHomePage();
    void toCarrelloPage();
public slots:
    void showHomePage();
    void showCarrelloPage();
};

#endif // COCKTAILPAGE_H
