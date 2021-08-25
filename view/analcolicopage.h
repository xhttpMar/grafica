#ifndef ANALCOLICOPAGE_H
#define ANALCOLICOPAGE_H

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
#include <QSpinBox>
#include <QSizePolicy>

class AnalcolicoPage : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* AnalcolList;
    QPushButton* back;
    QPushButton* cart;
    QPushButton* add;
    QSpinBox* quantity;
public:
    explicit AnalcolicoPage(QWidget* paret = nullptr);
    void addItems();
signals:
    void toHomePage();
    void toCarrelloPage();
public slots:
    void showHomePage();
    void showCarrelloPage();
};

#endif
