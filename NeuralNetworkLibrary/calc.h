#ifndef CALC_H
#define CALC_H

#include <QList>


class Calc {
public:
    Calc();

    static double sigmoid(double x);

    double sigmoidDerivative(double x);

    static QList<double> costVector(QList<double> output, QList<double> goal);
};

#endif // CALC_H
