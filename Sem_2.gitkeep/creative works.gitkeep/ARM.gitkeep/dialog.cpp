#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(RealEstateValuation *a, int b,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    q = b;
    this->a = a;

    ui->setupUi(this);
    ui->label->setText("Стоимость");
    ui->label_2->setText("Площадь");
    ui->label_3->setText("Этаж");
    ui->label_4->setText("Этажность");
}

Dialog::Dialog(RealEstateValuation *a,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    q=0;
    this->a = a;
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{

    switch (q) {
    case 0:{
        QString aa = ui->lineEdit->text();
        QString b = ui->lineEdit_2->text();
        QString c = ui->lineEdit_3->text();
        QString d = ui->lineEdit_4->text();
        a->setObject(aa.toDouble(), b.toDouble(), c.toDouble(), d);
        close();
        break;}

    case 1:{

        QString aa = ui->lineEdit->text();
        QString b = ui->lineEdit_2->text();
        QString c = ui->lineEdit_3->text();
        QString d = ui->lineEdit_4->text();
        a->setAnalog1(aa.toDouble(), b.toDouble(), c.toDouble(), d.toDouble());
        close();
        break;}
    case 2:{



        QString aa = ui->lineEdit->text();
        QString b = ui->lineEdit_2->text();
        QString c = ui->lineEdit_3->text();
        QString d = ui->lineEdit_4->text();
        a->setAnalog2(aa.toDouble(), b.toDouble(), c.toDouble(), d.toDouble());
        close();
        break;}
    case 3:{

        QString aa = ui->lineEdit->text();
        QString b = ui->lineEdit_2->text();
        QString c = ui->lineEdit_3->text();
        QString d = ui->lineEdit_4->text();
        a->setAnalog3(aa.toDouble(), b.toDouble(), c.toDouble(), d.toDouble());
        close();
        break;}
    case 4:{


        QString aa = ui->lineEdit->text();
        QString b = ui->lineEdit_2->text();
        QString c = ui->lineEdit_3->text();
        QString d = ui->lineEdit_4->text();
        a->setAnalog4(aa.toDouble(), b.toDouble(), c.toDouble(), d.toDouble());
        close();
        break;}
    }
}



