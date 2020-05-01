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

    QVector<QVector<double>> *weights;
    QVector<double> *biases;
};

#endif // LAYER_H
