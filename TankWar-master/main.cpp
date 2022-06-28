#include <QApplication>
#include "mainwindow.h"
#include "dialog.h"
#include "PlayerTank.h"
#include "Bullet.h"
#include "QTextCodec"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    //调整界面自适应屏幕
    QApplication a(argc, argv);

    QApplication::addLibraryPath("./plugins");

    Dialog d;
    d.setWindowOpacity(0.90);
    d.show();
    return a.exec();
}
