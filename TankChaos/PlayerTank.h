#ifndef MYTANK_H
#define MYTANK_H

#include "Tank.h"
#include "Bullet.h"
#include "QKeyEvent"
#include "QVector"
#include "QTimer"
#include "qobject.h"

class MyTank : public QObject, public Tank
{
      Q_OBJECT
public:
    MyTank();
    ~MyTank();
    void fire();
public slots:
    void move();
public:
    Bullet *bullet;
    QVector<Bullet *> bullet_vector;
public:
    QTimer *timer;
    bool up;
    bool down;
    bool left;
    bool right;
};

#endif // MYTANK_H
