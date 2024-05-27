#ifndef ADDNODE_H
#define ADDNODE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class addNode;
}

class addNode : public QDialog
{
    Q_OBJECT

public:
    explicit addNode(QWidget *parent = nullptr);
    ~addNode();

signals:     void dataReady(const QString& data);
private slots:
    void on_pushButton_clicked();

private:
    Ui::addNode *ui;
};

#endif // ADDNODE_H
