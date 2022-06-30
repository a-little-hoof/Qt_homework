#include "dialog_2.h"
#include "ui_dialog_2.h"
#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "dialog_1.h"
#include "QPainter"
#include "mainwindow2.h"

Dialog_2::Dialog_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_2)
{
    ui->setupUi(this);
}

Dialog_2::~Dialog_2()
{
    delete ui;
}

void Dialog_2::on_pushButton_3_clicked()
{
    Dialog *d =new Dialog();
    d->show();
    this->close();
}

void Dialog_2::on_pushButton_clicked()
{
    MainWindow *m = new MainWindow();

    m->show();  // 显示新窗口
    this->close();
}

void Dialog_2::on_pushButton_2_clicked()
{
    MainWindow2 *m = new MainWindow2();
    m->show();
    this->close();
}
