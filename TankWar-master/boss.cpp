#include "boss.h"
#include "ctime"
Boss::Boss()
{

}

Boss::Boss(int x, int y, int dir)
{

    this->x = x;
    this->y =y;
    this->dir =dir;
    isAlive = true;
    speed = 18;
    hp=3;

}


void Boss::run()
{
    int movnum=10;
    while(isAlive)
    {
        srand(clock());
        Boss::msleep(65);         // 睡眠
        dir = qrand()%4;
        switch(dir)
        {
        case 0:
            for(int i=0;i<movnum;i++)
            {
                if(dir==0)
                {
                    Boss::msleep(70);
                    if(y>5&&dir==0)
                    {
                        y -= speed;
                    }
                    else{
                        dir=1;
                        break;
                    }
                }

            }
            break;
        case 1:
            for(int i=0;i<movnum;i++)
            {
                if(dir==1)
                {
                    Boss::msleep(70);
                    if(y<550)
                    {
                        y += speed;
                    }
                    else {
                        dir=0;
                        break;
                    }
                }
            }
            break;
        case 2:
            for(int i=0;i<movnum;i++)
            {
                if(dir==2)
                {
                    Boss::msleep(70);
                    if(x>10)
                    {
                        x -= speed;
                    }
                    else
                    {
                        dir=3;
                        break;
                    }
                }
            }
            break;
        case 3:
            for(int i=0;i<movnum;i++)
            {
                if(dir==3)
                {
                    Boss::msleep(70);
                    if(x<840)
                    {
                        x +=  speed;
                    }
                    else{
                        dir=2;
                        break;
                    }
                }
            }
            break;
        }
    }
}
