#ifndef BULLET_H
#define BULLET_H

#include "QThread"

class Bullet : public QThread
{
public:
    Bullet();
    Bullet(int x,int y,int dir);
    void run();
    ~Bullet();
public:
    int x;        // 纵坐标
    int y;        // 横坐标
    int count;    // 子弹的数量
    int dir;      // 判断子弹的方向
    int speed;
    bool isAlive;


};

#endif // BULLET_H
