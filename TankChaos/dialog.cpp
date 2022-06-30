#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "dialog_1.h"
#include "QPainter"
#include "dialog_2.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


}


Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    Dialog_2 *d =new Dialog_2();
    d->show();
    this->close();
}


void Dialog::on_L_Reco_clicked()
{
    Dialog_1 *d =new Dialog_1();
    d->show();

}


void Dialog::on_EXIT_clicked()
{
    this->close();
}
