#include "header.h"


Header::Header(QPushButton *sx, QLabel *titolo, QPushButton *dx)
{
    QHBoxLayout* h = new QHBoxLayout();
    h->addWidget(sx);
    h->addWidget(titolo);
    h->addWidget(dx);

    h->setAlignment(sx,Qt::AlignLeft);
    h->setAlignment(titolo,Qt::AlignCenter);
    h->setAlignment(dx,Qt::AlignRight);
    setLayout(h);
}
