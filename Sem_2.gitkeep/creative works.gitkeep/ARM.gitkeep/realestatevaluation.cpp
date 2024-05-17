#include "realestatevaluation.h"

RealEstateValuation::RealEstateValuation()
{

}

void RealEstateValuation::calculationMetr(){
    analog1.push_back(analog1[0]/analog1[1]);
    analog2.push_back(analog2[0]/analog2[1]);
    analog3.push_back(analog3[0]/analog3[1]);
    analog4.push_back(analog4[0]/analog4[1]);
}
void RealEstateValuation::calcMetrBid(){
    analog1[4] = analog1[4] + analog1[4]*bidAdjustment/100;
    analog2[4] = analog2[4] + analog2[4]*bidAdjustment/100;
    analog3[4] = analog3[4] + analog3[4]*bidAdjustment/100;
    analog4[4] = analog4[4] + analog4[4]*bidAdjustment/100;
}
void RealEstateValuation::calcAdjS(){
    analog1[4]=analog1[4]*(1+(((1.266*pow(objectEvaluation[0],-0.089))/(1.266*pow(analog1[1],-0.089))-1)*100)/100);
    analog2[4]=analog2[4]*(1+(((1.266*pow(objectEvaluation[0],-0.089))/(1.266*pow(analog2[1],-0.089))-1)*100)/100);
    analog3[4]=analog3[4]*(1+(((1.266*pow(objectEvaluation[0],-0.089))/(1.266*pow(analog3[1],-0.089))-1)*100)/100);
    analog4[4]=analog4[4]*(1+(((1.266*pow(objectEvaluation[0],-0.089))/(1.266*pow(analog4[1],-0.089))-1)*100)/100);
    analog1.push_back((((1.266*pow(objectEvaluation[0],-0.089))/(1.266*pow(analog1[1],-0.089))-1)*100));
    analog2.push_back((((1.266*pow(objectEvaluation[0],-0.089))/(1.266*pow(analog2[1],-0.089))-1)*100));
    analog3.push_back((((1.266*pow(objectEvaluation[0],-0.089))/(1.266*pow(analog3[1],-0.089))-1)*100));
    analog4.push_back((((1.266*pow(objectEvaluation[0],-0.089))/(1.266*pow(analog4[1],-0.089))-1)*100));
}
double RealEstateValuation::calcAdjFloor(vector<double> a){
    if (objectEvaluation[1] == 1){
        if (a[2] == 1) return 0;
        if (a[2] == a[3]) return -2;
        return -3;
    }
    if (objectEvaluation[1] == objectEvaluation[2]){
        if (a[2] == 1) return 2;
        if (a[2] == a[3]) return 0;
        return -1;
    }
    else{
        if (a[2] == 1) return 3;
        if (a[2] == a[3]) return 0;
        return 1;
    }
}

void RealEstateValuation::calcAdjFloor(){
    analog1.push_back(calcAdjFloor(analog1));
    analog2.push_back(calcAdjFloor(analog2));
    analog3.push_back(calcAdjFloor(analog3));
    analog4.push_back(calcAdjFloor(analog4));
}
void RealEstateValuation::calcMetrFloor(){
    analog1[4] = analog1[4]*(1+analog1[6]/100);
    analog2[4] = analog2[4]*(1+analog2[6]/100);
    analog3[4] = analog3[4]*(1+analog3[6]/100);
    analog4[4] = analog4[4]*(1+analog4[6]/100);
}
void RealEstateValuation::allAdj(){
    analog1.push_back(abs(analog1[5])+abs(analog1[6])+abs(bidAdjustment));
    analog2.push_back(abs(analog2[5])+abs(analog2[6])+abs(bidAdjustment));
    analog3.push_back(abs(analog3[5])+abs(analog3[6])+abs(bidAdjustment));
    analog4.push_back(abs(analog4[5])+abs(analog4[6])+abs(bidAdjustment));
}
void RealEstateValuation::importanceRatio(){
    analog1.push_back((1-analog1[7]/(analog1[7]+analog2[7]+analog3[7]+analog4[7]))/3);
    analog2.push_back((1-analog2[7]/(analog1[7]+analog2[7]+analog3[7]+analog4[7]))/3);
    analog3.push_back((1-analog3[7]/(analog1[7]+analog2[7]+analog3[7]+analog4[7]))/3);
    analog4.push_back((1-analog4[7]/(analog1[7]+analog2[7]+analog3[7]+analog4[7]))/3);
}
void RealEstateValuation::calcMetrOE(){
    objectEvaluation.push_back(analog1[4]*analog1[8]+analog2[4]*analog2[8]+analog3[4]*analog3[8]+analog4[4]*analog4[8]);
}
