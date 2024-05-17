#ifndef REALESTATEVALUATION_H
#define REALESTATEVALUATION_H

#include <vector>
#include <string>
#include <math.h>
#include <iostream>
#include "QString"

using namespace std;

class RealEstateValuation
{
    QString objectAddress;
    string analogAddress1;
    string analogAddress2;
    string analogAddress3;
    string analogAddress4;

   vector<double> objectEvaluation;
   vector<double> analog1;
   vector<double> analog2;
   vector<double> analog3;
   vector<double> analog4;

   double bidAdjustment=-5;

public:
    RealEstateValuation();
    void setObject(double a, double b, double c, QString d){
        objectEvaluation.push_back(a);
         objectEvaluation.push_back(b);
          objectEvaluation.push_back(c);
          objectAddress = d;
    };

    void setAnalog1(double a, double b, double c,double d){
        analog1.push_back(a);
        analog1.push_back(b);
        analog1.push_back(c);
        analog1.push_back(d);
    };
    void setAnalog2(double a, double b, double c,double d){
        analog2.push_back(a);
        analog2.push_back(b);
        analog2.push_back(c);
        analog2.push_back(d);
    };
    void setAnalog3(double a, double b, double c,double d){
        analog3.push_back(a);
        analog3.push_back(b);
        analog3.push_back(c);
        analog3.push_back(d);
    };
    void setAnalog4(double a, double b, double c,double d){
        analog4.push_back(a);
        analog4.push_back(b);
        analog4.push_back(c);
        analog4.push_back(d);
    };

    double getP(){ return  objectEvaluation[3]; }
    QString getAd(){return objectAddress;}
    QString getS(){return QString::number(objectEvaluation[0]);}

    void calculationMetr();
    void calcMetrBid();
    void calcAdjS();
    double calcAdjFloor(vector<double> a);
    void calcAdjFloor();
    void calcMetrFloor();
    void allAdj();
    void importanceRatio();
    void calcMetrOE();
    void start(){
        calculationMetr();
        calcMetrBid();
        calcAdjS();
        calcAdjFloor();
        calcMetrFloor();
        allAdj();
        importanceRatio();
        calcMetrOE();
    };
    void print(){
        cout << objectEvaluation[0]<< endl;
        cout << objectEvaluation[1]<< endl;
        cout << objectEvaluation[2]<< endl;
        cout << objectEvaluation[3]<< endl;

    };
};

#endif // REALESTATEVALUATION_H
