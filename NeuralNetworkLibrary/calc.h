#ifndef CALC_H
#define CALC_H


class Calc {
public:
    Calc();

    static double sigmoid(double x);

    double sigmoidDerivative(double x);
};

#endif // CALC_H
