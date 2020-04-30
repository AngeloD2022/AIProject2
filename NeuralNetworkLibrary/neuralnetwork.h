#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "layer.h"
#include "QList"
#include <QtMath>

class NeuralNetwork {
public:
    NeuralNetwork(int *configuration[]);

private:

    // # Layers = total layers - input
    QList<Layer *> *layers;
    int *config;


};

#endif // NEURALNETWORK_H
