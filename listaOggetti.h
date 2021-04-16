#ifndef listaOggetti_H
#define listaOggetti_H

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

class listaOggetti: public QWidget {
    Q_OBJECT
public:
    explicit listaOggetti(QWidget *parent = nullptr);

};

#endif // listaOggetti_H
