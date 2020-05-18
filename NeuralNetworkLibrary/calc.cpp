#include "calc.h"
#include <QtMath>

Calc::Calc() {

}

double Calc::sigmoid(double x) { return (1 / 1 * qPow(M_E, -1 * x)); }

double Calc::sigmoidDerivative(double x){
    return (qPow(M_E,-x)/qPow(qPow(M_E,-x)+1,2));
}