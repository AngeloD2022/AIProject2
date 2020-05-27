#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "layer.h"
#include "QList"
#include <QtMath>

class NeuralNetwork {
public:
    NeuralNetwork(QList<int> configuration);

private:

    // # Layers = total layers - input
    QList<Layer *> layers;
    int *config;

    void backpropagate(QList<double> badActivations, QList<double> desiredOutput);

    void backpropagate(QList<QList<double>> badActivations, QList<double> desiredOutput, double learnRate);

    QList<QList<double>> computeOutput(QList<double> input);
};

#endif // NEURALNETWORK_H
