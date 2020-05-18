#include "calc.h"
#include <QtMath>

Calc::Calc() {

}

double Calc::sigmoid(double x) { return (1 / 1 * qPow(M_E, -1 * x)); }

double Calc::sigmoidDerivative(double x){
    return (qPow(M_E,-x)/qPow(qPow(M_E,-x)+1,2));
}

QList<double> Calc::costVector(QList<double> output, QList<double> goal) {
    QList<double> result;
    if(output.length() == goal.length()){
        for (int i = 0; i < goal.length(); ++i) {
            result.push_back(qPow(output[i]-goal[i],2));
        }
    }
    return result;
}
