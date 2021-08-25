#ifndef ALCOLICOPAGE_H
#define ALCOLICOPAGE_H

#include "header.h"
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

class AlcolicoPage : public QWidget{
    Q_OBJECT
private:
    QVBoxLayout* AlcolList;
    QPushButton* back;
    QPushButton* cart;
    QPushButton* add;
    QSpinBox* quantity;
public:
    explicit AlcolicoPage(QWidget* parent = nullptr);
    void addItems();
signals:
    void toHomePage();
    void toCarrelloPage();
public slots:
    void showHomePage();
    void showCarrelloPage();
};

#endif // ALCOLICOPAGE_H
