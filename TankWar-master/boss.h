#ifndef BOSS_H
#define BOSS_H

#include <QMainWindow>
#include <QObject>
#include"Tank.h"
#include "QThread"
#include "QVector"
#include "Bullet.h"
#include "qdebug.h"
#include "PlayerTank.h"

class Boss:public Tank, public QThread
{
public:
    Boss();
    Boss(int x, int y, int dir);
    void run();
public:
    Bullet *bs_bullet;
    QVector<Bullet *> bs_bullet_vector;
    int hp;
};

#endif // BOSS_H
