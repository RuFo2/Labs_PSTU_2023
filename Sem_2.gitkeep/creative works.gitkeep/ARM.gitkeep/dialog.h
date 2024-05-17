#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "realestatevaluation.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(RealEstateValuation *a,int b,QWidget *parent = nullptr);
    explicit Dialog(RealEstateValuation *a,QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    RealEstateValuation *a;
    int q = 0;

};

#endif // DIALOG_H
