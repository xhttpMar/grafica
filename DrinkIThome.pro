QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    model/bevanda.cpp \
    model/carrello.cpp \
    model/catalogo.cpp \
    model/ciao.cpp \
    model/cibo.cpp \
    model/cocktail.cpp \
    model/deepptr.cpp \
    model/ingrediente.cpp \
    model/prodotto.cpp \
    view.cpp \
    view/alcolicopage.cpp \
    view/analcolicopage.cpp \
    view/carrellopage.cpp \
    view/cocktailpage.cpp \
    view/header.cpp \
    view/home.cpp \
    view/ingredientpage.cpp

HEADERS += \
    ../PROGETTO/bevanda.h \
    ../PROGETTO/carrello.h \
    ../PROGETTO/catalogo.h \
    ../PROGETTO/cibo.h \
    ../PROGETTO/cocktail.h \
    ../PROGETTO/deepptr.h \
    ../PROGETTO/ingrediente.h \
    ../PROGETTO/prodotto.h \
    ../PROGETTO/vettore.h \
    model/bevanda.h \
    model/carrello.h \
    model/catalogo.h \
    model/ciao.h \
    model/cibo.h \
    model/cocktail.h \
    model/deepptr.h \
    model/ingrediente.h \
    model/prodotto.h \
    model/vettore.h \
    view.h \
    view/alcolicopage.h \
    view/analcolicopage.h \
    view/carrellopage.h \
    view/cocktailpage.h \
    view/header.h \
    view/home.h \
    view/ingredientpage.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    data/beer.png \
    data/cocktail.png \
    data/hamburger.png \
    data/shopping-cart (2).png \
    data/shopping-cart.png \
    data/softdrinks.png

RESOURCES += \
    data/icons.qrc
