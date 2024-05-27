#include "addedge.h"
#include "ui_addedge.h"
#include <QString>

addEdge::addEdge(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addEdge)
{
    ui->setupUi(this);
}

addEdge::~addEdge()
{
    delete ui;
}

void addEdge::on_pushButton_clicked()
{
    QString first = ui->firstNode->text(); // считывание полей ввода
    QString second = ui->secondNode->text();
    QString weidht = ui->weidht->text();
    emit dataR(first, second, weidht); // подача сигнала для передачи значений в другое окно
    close();
}

