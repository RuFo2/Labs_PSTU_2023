#ifndef ADDEDGE_H
#define ADDEDGE_H

#include <QDialog>

namespace Ui {
class addEdge;
}

class addEdge : public QDialog
{
    Q_OBJECT

public:
    explicit addEdge(QWidget *parent = nullptr);
    ~addEdge();

signals: void dataR(const QString&first,const QString&second,const QString&weidht);
private slots:
    void on_pushButton_clicked();

private:
    Ui::addEdge *ui;
};

#endif // ADDEDGE_H
