#ifndef Home_H
#define Home_H
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


class Home: public QWidget {
    Q_OBJECT
public:
    explicit Home(QWidget *parent = nullptr);
};

#endif // Home_H
