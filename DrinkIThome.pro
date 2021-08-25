QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    view.cpp \
    view/alcolicopage.cpp \
    view/analcolicopage.cpp \
    view/carrello.cpp \
    view/ciao.cpp \
    view/cocktailpage.cpp \
    view/header.cpp \
    view/home.cpp \
    view/ingredientpage.cpp

HEADERS += \
    view.h \
    view/alcolicopage.h \
    view/analcolicopage.h \
    view/carrello.h \
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
