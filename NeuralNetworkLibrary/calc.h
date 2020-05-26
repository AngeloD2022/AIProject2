#ifndef CALC_H
#define CALC_H

#include <QList>


class Calc {
public:
    Calc();

    static QList<double> vectorAdd(QList<double> a, QList<double> b);

    static double sigmoid(double x);

    static double sigmoidDerivative(double x);

    static QList<double> costVector(QList<double> output, QList<double> goal);

    static QList<double> sigmoidDerivative(QList<double> x);

    static QList<double> sigmoid(QList<double> x);

    static QList<double> costDerivative(QList<double> output, QList<double> desiredOutput);
};

#endif // CALC_H
