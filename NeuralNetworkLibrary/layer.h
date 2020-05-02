#ifndef LAYER_H
#define LAYER_H

#include "calc.h"
#include <QtMath>
#include <QVector>
#include <QList>
#include <QRandomGenerator64>

class Layer {

public:
    Layer(int inputs, int outputs);

protected:
    QVector<QVector<double>> weights;
    QVector<double> biases;
    QVector<double> computeActivations(QVector<double> inputs);

private:
    int inputs;
    int outputs;
};

#endif // LAYER_H
