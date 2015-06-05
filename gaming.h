#ifndef GAMING_H
#define GAMING_H

#include <QWidget>
#include <mainwindow.h>


class gaming : public QWidget
{
    Q_OBJECT
public:
    explicit gaming();

    void picture(int num);

signals:

public slots:
};

#endif // GAMING_H
