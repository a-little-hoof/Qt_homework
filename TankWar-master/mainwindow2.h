#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include "PlayerTank.h"
#include "Bullet.h"
#include "EnemyTank.h"
#include <time.h>
#include <QVector>
#include "boss.h"

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT
public slots:
    void collision_attack_p1_p2();      // p1子弹和p2坦克的碰撞检测
    void collision_attack_p2_p1();      // p2子弹和p1子弹的碰撞检测

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();
    MyTank  p1Tank;
    MyTank  p2Tank;
    Bullet  bullet;
    Bullet  *bul1;
    QTimer *timer;
    QTimer *timeradd;
private slots:
    void on_EXIT_clicked();
private:
    void paintEvent(QPaintEvent *event);       // 绘图
    void keyPressEvent(QKeyEvent *);           // 键盘响应
    void mousePressEvent(QMouseEvent *);       // 鼠标响应
    void PaintAll(int x,int y,QString a,int target_x,int target_y,int source_x,int source_y);
public:
    int bullet_size;
private:
    Ui::MainWindow2 *ui;
};

#endif // MAINWINDOW2_H
