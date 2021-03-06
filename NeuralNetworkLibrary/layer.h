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

    QList<double> backpropagate(QList<double> costDerivatives, QList<double> badInput, QList<double> myBadOutput,
                                double learnRate);
    QList<double> computeActivations(QList<double> inputs);

protected:
    QVector<QVector<double>> weights;
    QVector<double> biases;


private:
    int inputs;
    int outputs;

    QList<double> computeWeightedSums(QList<double> inputs);
};

#endif // LAYER_H
