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

    void backpropagate(QList<double> de2dy);

    void backpropagate(QList<double> de2dy, QList<double> badLayerActivations);

    void backpropagate(QList<double> costDerivatives, QList<double> badInput, QList<double> myBadOutput,
                       double learnRate);

    QList<double> computeWeightedSums(QList<double> inputs);
};

#endif // LAYER_H
