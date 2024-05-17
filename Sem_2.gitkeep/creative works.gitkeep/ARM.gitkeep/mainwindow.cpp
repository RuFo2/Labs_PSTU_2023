#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a = new RealEstateValuation;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (wi!= nullptr) delete  wi;
    wi = new Dialog(a);
    wi->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    delete  wi;
    wi = new Dialog(a,1);
    wi->show();

}


void MainWindow::on_pushButton_3_clicked()
{
    delete  wi;
    wi = new Dialog(a,2);
    wi->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    delete  wi;
    wi = new Dialog(a,3);
    wi->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    delete  wi;
    wi = new Dialog(a,4);
    wi->show();
}


void MainWindow::on_pushButton_6_clicked()
{
    a->start();
    ui->textBrowser->append(a->getAd());
    ui->textBrowser->append("Стоимость: " + QString::number(a->getP()));
    ui->textBrowser->append("Площадь " + a->getS());
    ui->textBrowser->setStyleSheet("font: 14 px");

    a->print();
}

