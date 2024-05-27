#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graph.h"
#include "addnode.h"
#include <QGraphicsScene>
#include <QMainWindow>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include<QtMath>

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
    Graph *gr = new Graph;

private slots:
    void on_addNode_clicked();
    void receiveData(const QString& data);
    void recEdge(const QString&first,const QString&second,const QString&weidht);
    void on_delNode_clicked();
    void updateLine();
    void on_addEdge_clicked();
    void on_upd_clicked();
    void on_tsp_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *Scene;


};
#endif // MAINWINDOW_H
