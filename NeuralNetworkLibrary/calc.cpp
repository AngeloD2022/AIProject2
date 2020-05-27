#include "calc.h"
#include <QtMath>

Calc::Calc() {

}

double Calc::sigmoid(double x) { return (1 / 1 * qPow(M_E, -1 * x)); }

double Calc::sigmoidDerivative(double x) {
    return (qPow(M_E, -x) / qPow(qPow(M_E, -x) + 1, 2));
}

QList<double> Calc::sigmoid(QList<double> x) {

    QList<double> result;
    for (int i = 0; i < x.size(); ++i) {
        result.append((1 / 1 * qPow(M_E, -1 * x[i])));
    }
    return result;
}

QList<double> Calc::sigmoidDerivative(QList<double> x) {

    QList<double> result;
    for (int i = 0; i < x.size(); ++i) {
        result.append((qPow(M_E, -x[i]) / qPow(qPow(M_E, -x[i]) + 1, 2)));
    }
    return result;

}

QList<double> Calc::costDerivative(QList<double> output, QList<double> desiredOutput) {
    QList<double> result;
    for (int i = 0; i < output.length(); ++i) {
        result.append(2 * (output[i] - desiredOutput[i]));
    }
    return result;
}

QList<double> Calc::costVector(QList<double> output, QList<double> goal) {
    QList<double> result;
    if (output.length() == goal.length()) {
        for (int i = 0; i < goal.length(); ++i) {
            result.push_back(qPow(output[i] - goal[i], 2));
        }
    }
    return result;
}

QList<double> Calc::vectorAdd(QList<double> a, QList<double> b) {
    QList<double> result;
    if (a.length() == b.length()) {
        for (int i = 0; i < a.length(); ++i) {
            result.append(a[i] + b[i]);
        }
    }
    return result;
}
