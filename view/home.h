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
#include <QButtonGroup>


class Home: public QWidget {
    Q_OBJECT

    public:
    explicit Home(QWidget *parent = nullptr);
    //virtual ~Home();
    void addProducts();

    private:
    QVBoxLayout* LayoutMain;
    QButtonGroup* ProdottiGroup;
    QHBoxLayout* ProdottiLayout;
    QPushButton* cocktails;
    QPushButton* alcolici;
    QPushButton* analcolici;
    QPushButton* cibo;
    QPushButton* carrello;

    signals:
        void toCocktailPage();
        void toAlcolicoPage();
        void toAnalcolicoPage();
        void toCarrelloPage();
    public slots:
        void showCocktailPage();
        void showAlcolicoPage();
        void showAnalcolicoPage();
        void showCarrelloPage();
};

#endif // Home_H
