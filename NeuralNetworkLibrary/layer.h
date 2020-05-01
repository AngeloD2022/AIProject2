#ifndef LAYER_H
#define LAYER_H

#include "calc.h"
#include <QtMath>
#include <QVector>
#include <QList>

class Layer {

public:
    Layer(int inputs, int outputs);

private:

    int inputs;
    int outputs;
    QVector<QVector<double>> weights;
    QVector<double> biases;

    QVector<double> computeActivations(QVector<double> inputs);
};

#endif // LAYER_H
