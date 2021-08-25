#ifndef INGREDIENTPAGE_H
#define INGREDIENTPAGE_H

#include "view/header.h"

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QFrame>
#include <QScrollArea>
#include <QScrollBar>
#include <QLabel>
#include <QListView>
#include <QLineEdit>
#include <QWidgetAction>
#include <QFormLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <QString>
#include <iostream>
#include <QTabWidget>
#include <QSpinBox>
#include <QSizePolicy>

class IngredientPage : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* mainLayout;
    QPushButton* back;
    QPushButton* switchToCarrello;
    QLabel* quantity;
public:
    explicit IngredientPage(QWidget* parent = nullptr);
    void addList();
signals:
    void toHomePage();
    void toCarrelloPage();
public slots:
    void showHomePage();
    void showCarrelloPage();
};

#endif // INGREDIENTPAGE_H
