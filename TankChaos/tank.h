#ifndef TANK_H
#define TANK_H

class Tank
{
public:
    Tank();
    void fire();
public:
    int x;
    int y;
    int dir;
    int speed;
    int hp;
    bool isAlive;
};

#endif // TANK_H
