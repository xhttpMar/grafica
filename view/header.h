#ifndef HEADER_H
#define HEADER_H

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>

class Header: public QWidget {
    Q_OBJECT
public:
    explicit Header(QPushButton* sx, QLabel* titolo, QPushButton* dx);
};

#endif // HEADER_H
