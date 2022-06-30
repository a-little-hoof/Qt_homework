# 设计说明

本程序基于 Qt5.12 完成了一个坦克大战的设计，单人玩家控制1个主坦克，可以发射子弹、自由移动。

胜利条件是击败在场的所有BOSS坦克。

失败条件是我方血量为0。

操作按键：WASD控制坦克移动，单击鼠标进行射击

# 界面展示

## 欢迎界面

![](screenshot/start.png)

## 帮助

![](screenshot/help.png)

## 游戏进行

![](screenshot/game.png)

## 游戏失败

![](screenshot/lose.png)

## 游戏胜利

![](screenshot/win.png)

# 文件结构

```
子弹类
Bullet.h/cpp

坦克类
Tank.h/cpp
PlayerTank.h/cpp
EnemyTank.h/cpp
boss.h/cpp

窗口对话框类
mainwindow.h/cpp
dialog.h/cpp
dialog_1.h/cpp

图片文件

```

# 各个类的功能

## 坦克类

```C++
class Tank
{
public:
    Tank();
    void fire();
public:
    int x;          // 纵坐标
    int y;          // 横坐标
    int dir;        // 坦克的方向
    int speed;      // 坦克的速度
    int hp;         // 坦克的生命值
    bool isAlive;   // 坦克的是否还活着
};
```

主要功能：提供基类

## 玩家坦克类

```C++
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
    bool up;        // 辅助方向标记上
    bool down;      // 辅助方向标记下
    bool left;      // 辅助方向标记左
    bool right;     // 辅助方向标记右
};
```

主要功能：移动、开火

## 敌方坦克类

```C++
class EnemyTank: public Tank, public QThread
{
public:
    EnemyTank();
    EnemyTank(int x, int y, int dir);
    void run();
public:
    Bullet *en_bullet;
    QVector<Bullet *> en_bullet_vector;
};
```

主要功能：移动、开火

## 子弹类

```C++
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
    int count;    // 武器子弹的数量
    int dir;      // 判断子弹的方向
    int speed;    // 子弹的速度
    bool isAlive; // 是否存活，决定是否显示
};
```

主要功能：移动、开火

## 游戏控制类

```C++
class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void collision_attack_player_enemy();      // 我方子弹和敌方坦克的碰撞检测
    void collision_bullet_player_enemy();      // 我方子弹和敌方子弹的碰撞检测
    void collision_tank_enemy_enemy();         // 敌方子弹和敌方子弹的碰撞检测
    void collision_bullet_enemy_player();      // 敌方子弹和我方坦克的碰撞检测
    void create_tank_enenmy();                 // 制造敌方坦克
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void paintEvent(QPaintEvent *event);       // 绘图
    void keyPressEvent(QKeyEvent *);           // 键盘响应
    void keyReleaseEvent(QKeyEvent *);         // 键盘松开
    void mousePressEvent(QMouseEvent *);       // 鼠标响应
    void PaintAll(int x,int y,QString a,int target_x,int target_y,int source_x,int source_y);
public:
    MyTank  myTank;
    Bullet  bullet;
    Bullet  *bul1;
    EnemyTank enemytank;
    QVector<EnemyTank *> vector_enemy;

    QTimer *timer;
    QTimer *timeradd;

    int getx;             // 用于子弹的绘制
    int gety;
    QString str_score;    // 得分控制
    int int_score;
    QString str_life;     // 坦克生命控制
    int enemy_size;       // 敌方坦克数量
    int bullet_size;
private slots:
    void on_EXIT_clicked();
    void on_L_Request_destroyed();
private:
    Ui::MainWindow *ui;
};
```