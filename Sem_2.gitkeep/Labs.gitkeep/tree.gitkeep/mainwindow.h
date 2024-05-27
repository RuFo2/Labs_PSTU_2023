#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QString>
#include <QDebug>
#include <QtCore>
#include <QtGui>

#include "tree.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_showBtn_clicked();
    void showTre(Node *tree, int x, int y);

    //void on_radioButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *Scene;
    QGraphicsEllipseItem *ell;
    QGraphicsLineItem *line;
    QGraphicsTextItem *text;

};
#endif // MAINWINDOW_H
