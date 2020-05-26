#ifndef CALC_H
#define CALC_H

#include <QList>


class Calc {
public:
    Calc();

    static double sigmoid(double x);

    static double sigmoidDerivative(double x);

    static QList<double> costVector(QList<double> output, QList<double> goal);

    static QList<double> sigmoidDerivative(QList<double> x);

    static QList<double> sigmoid(QList<double> x);
};

#endif // CALC_H
