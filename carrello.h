#ifndef CARRELLO_H
#define CARRELLO_H

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


class Carrello: public QWidget {
    Q_OBJECT
public:
    explicit Carrello(QWidget *parent = nullptr);
};

#endif
