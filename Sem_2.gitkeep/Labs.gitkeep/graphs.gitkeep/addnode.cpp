#include "addnode.h"
#include "mainwindow.h"
#include "ui_addnode.h"
#include <QString>

addNode::addNode(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addNode)
{
    ui->setupUi(this);

}

addNode::~addNode()
{
    delete ui;
}

void addNode::on_pushButton_clicked()
{
    QString dat = ui->lineEdit->text(); //считывание поля ввода
    emit dataReady(dat); // отправка сигнала другому окну
    close();
}

