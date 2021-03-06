#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPainter"
#include "qbitmap.h"
#include "QKeyEvent"
#include "qdebug.h"
#include "QDebug"
#include "QMessageBox"
#include "iterator"
#include "QLabel"
#include "math.h"
#include <QTimer>
#include <string>

void MainWindow2::collision_attack_p1_p2()
{
    if(p1Tank.isAlive)
    {
        for(int bcnt=0;bcnt<p1Tank.bullet_vector.size();bcnt++)
        {
            Bullet *mbu=p1Tank.bullet_vector.at(bcnt);
            if(mbu->isAlive==true)
            {
                if(p2Tank.isAlive)
                {
                    if(mbu->x>=p2Tank.x && mbu->x<=(p2Tank.x+50)&& mbu->y>=p2Tank.y && mbu->y<=(p2Tank.y+50))
                    {
                        p2Tank.hp--;
                        if(p2Tank.hp==0)
                            p2Tank.isAlive=0;
                        mbu->isAlive=false;
                        QString str_score =" "+ QString::number(p2Tank.hp);
                        ui->label_3->setText(str_score);
                    }
                }
            }
        }
    }
}

void MainWindow2::collision_attack_p2_p1()
{
    if(p2Tank.isAlive)
    {
        for(int bcnt=0;bcnt<p2Tank.bullet_vector.size();bcnt++)
        {
            Bullet *mbu=p2Tank.bullet_vector.at(bcnt);
            if(mbu->isAlive==true)
            {
                if(p1Tank.isAlive==true)
                {
                    if(mbu->x>=p1Tank.x && mbu->x<=(p1Tank.x+50)&& mbu->y>=p1Tank.y && mbu->y<=(p1Tank.y+50))
                    {
                        p1Tank.hp--;
                        if(p1Tank.hp==0)
                            p1Tank.isAlive=0;
                        mbu->isAlive=false;
                        QString str_score =" "+ QString::number(p1Tank.hp);
                        ui->label_2->setText(str_score);
                    }
                }
            }
        }
    }
}

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    setWindowTitle("Tank Chaos");

    ui->label_2->setText("    5");
    ui->label_3->setText("    5");
    p1Tank.hp=5;
    p2Tank.hp=5;
    // ??????????????????????????????????????????
    timer = new QTimer;

    // ??????????????????
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));                           // ????????????
    connect(timer,SIGNAL(timeout()),this,SLOT(collision_attack_p1_p2()));    // ????????????-????????????
    connect(timer,SIGNAL(timeout()),this,SLOT(collision_attack_p2_p1()));    // ????????????-????????????

    connect(timer,SIGNAL(timeout()),this,SLOT(mboom(bool)));                        //
    connect(timer,SIGNAL(timeout()),this,SLOT(myshock()));                          //
    // ??????80???????????????????????????
    timer->start(80);

    // ????????????
    QPixmap pixmap(":/new/prefix1/image/bg2.jpg");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::on_EXIT_clicked()
{
    this->close();
}

void MainWindow2::paintEvent(QPaintEvent *event)
{
    if(p1Tank.isAlive==true)
    {
        // ??????????????????
        switch(p1Tank.dir)
        {
        case 0:
        {
            QString qs=":/new/prefix1/image/mytank (1).png";
            PaintAll(p1Tank.x,p1Tank.y,qs,50,50,50,50);
            break;
        }
        case 1:
        {
            QString qs=":/new/prefix1/image/mytank (2).png";
            PaintAll(p1Tank.x,p1Tank.y,qs,50,50,50,50);
            break;
        }
        case 2:
        {
            QString qs=":/new/prefix1/image/mytank (3).png";
            PaintAll(p1Tank.x,p1Tank.y,qs,50,50,50,50);
            break;
        }
        case 3:
        {
            QString qs=":/new/prefix1/image/mytank (4).png";
            PaintAll(p1Tank.x,p1Tank.y,qs,50,50,50,50);
            break;
        }
        }

        // ???????????????????????????
        for(int bcnt=0 ; bcnt<p1Tank.bullet_vector.size() ;bcnt++)
        {
            Bullet *bu = p1Tank.bullet_vector.at(bcnt);
            if(bu->count!=0&& bu->isAlive==true)
            {
                QString qs=":/new/prefix1/image/my_bullet.png";
                PaintAll(bu->x,bu->y,qs,10,10,10,10);
            }
            if( bu->isAlive==false)
            {
                p1Tank.bullet_vector.remove(bcnt);
            }
        }
    }

    else
    {
        for(int boompic=0;boompic<20;boompic++)
        {
            if(0<=boompic&&boompic<=2)
            {
                QString qss=":/new/prefix1/image/Bomb_1";
                PaintAll(p1Tank.x,p1Tank.y,qss,60,60,60,60);
            }
            if(15<=boompic && boompic<=19)
            {
                QString qs=":/new/prefix1/image/Bomb_2";
                PaintAll(p1Tank.x,p1Tank.y,qs,60,60,60,60);
            }
        }
    }

    if(p2Tank.isAlive==true)
    {
        // ??????????????????
        switch(p2Tank.dir)
        {
        case 0:
        {
            QString qs=":/new/prefix1/image/mytank (1).png";
            PaintAll(p2Tank.x,p2Tank.y,qs,50,50,50,50);
            break;
        }
        case 1:
        {
            QString qs=":/new/prefix1/image/mytank (2).png";
            PaintAll(p2Tank.x,p2Tank.y,qs,50,50,50,50);
            break;
        }
        case 2:
        {
            QString qs=":/new/prefix1/image/mytank (3).png";
            PaintAll(p2Tank.x,p2Tank.y,qs,50,50,50,50);
            break;
        }
        case 3:
        {
            QString qs=":/new/prefix1/image/mytank (4).png";
            PaintAll(p2Tank.x,p2Tank.y,qs,50,50,50,50);
            break;
        }
        }

        // ???????????????????????????
        for(int bcnt=0 ; bcnt<p2Tank.bullet_vector.size() ;bcnt++)
        {
            Bullet *bu = p2Tank.bullet_vector.at(bcnt);
            if(bu->count!=0&& bu->isAlive==true)
            {
                QString qs=":/new/prefix1/image/my_bullet.png";
                PaintAll(bu->x,bu->y,qs,10,10,10,10);
            }
            if( bu->isAlive==false)
            {
                p2Tank.bullet_vector.remove(bcnt);
            }
        }
    }

    else
    {
        for(int boompic=0;boompic<20;boompic++)
        {
            if(0<=boompic&&boompic<=2)
            {
                QString qss=":/new/prefix1/image/Bomb_1";
                PaintAll(p2Tank.x,p2Tank.y,qss,60,60,60,60);
            }
            if(15<=boompic && boompic<=19)
            {
                QString qs=":/new/prefix1/image/Bomb_2";
                PaintAll(p2Tank.x,p2Tank.y,qs,60,60,60,60);
            }
        }
    }
}

void MainWindow2::keyPressEvent(QKeyEvent *k)
{
    if(k->key() == Qt::Key_W)     // ??????????????????
    {
        p2Tank.up=true;
        p2Tank.move();
    }
    else if(k->key()==Qt::Key_S ) // ??????????????????
    {
        p2Tank.down=true;
        p2Tank.move();
    }
    else if(k->key()==Qt::Key_A ) // ??????????????????
    {
        p2Tank.left=true;
        p2Tank.move();
    }
    else if (k->key()==Qt::Key_D) // ??????????????????
    {
        p2Tank.right=true;
        p2Tank.move();
    }
    else if (k->key()==Qt::Key_Q) // ????????????Q
    {
        if(p2Tank.bullet_vector.size()<bullet_size)
        p2Tank.fire();
    }
    else if(k->key() == Qt::Key_U)     // ??????????????????
    {
        p1Tank.up=true;
        p1Tank.move();
    }
    else if(k->key()==Qt::Key_J) // ??????????????????
    {
        p1Tank.down=true;
        p1Tank.move();
    }
    else if(k->key()==Qt::Key_H ) // ??????????????????
    {
        p1Tank.left=true;
        p1Tank.move();
    }
    else if (k->key()==Qt::Key_K) // ??????????????????
    {
        p1Tank.right=true;
        p1Tank.move();
    }


    this->repaint();
}
void MainWindow2::mousePressEvent(QMouseEvent *e)
{
    if(p1Tank.bullet_vector.size()<bullet_size)
    {
        p1Tank.fire();
    }
}
void MainWindow2::PaintAll(int x, int y, QString a, int target_x, int target_y, int source_x, int source_y)
{
    QRectF target(x,y, target_x, target_y);
    QRectF source(0, 0, source_x, source_y);
    QImage image(a);
    QPainter painter(this);
    painter.drawImage(target, image, source);
}
