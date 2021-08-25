#ifndef COCKTAILPAGE_H
#define COCKTAILPAGE_H

#include "view/header.h"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>
#include <QLabel>
#include <QSpinBox>
#include <QListWidget>

class CocktailPage: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* cocktailList;
    QPushButton* back;
    QPushButton* cart;
    QPushButton* add;
    QSpinBox* quantity;
public:
    explicit CocktailPage(QWidget* parent);
    void addItems();
signals:
    void toHomePage();
    void toCarrelloPage();
public slots:
    void showHomePage();
    void showCarrelloPage();
};

#endif // COCKTAILPAGE_H
