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
    QString first = ui->firstNode->text(); // Считывание первого поля ввода
    QString second = ui->secondNode->text(); // Считывание второго поля ввода
    QString weidht = ui->weidht->text(); // Считывание третьего поля ввода
    emit dataR(first, second, weidht); // подача сигнала для передачи значений в другое окно
    close();
}

