#ifndef LAYER_H
#define LAYER_H
#include "calc.h"
#include <QVector>

class Layer
{

public:
    Layer(int inputs, int outputs);
private:

    QVector<QList<double*>> weights;
    double *biases;
};
#endif // LAYER_H
