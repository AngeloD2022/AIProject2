#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include "layer.h"
#include "QList"

class NeuralNetwork
{
public:
    NeuralNetwork(int *configuration);

private:

    // # Layers = total layers - input
    QList<Layer*> *layers;
    void randomize();
};

#endif // NEURALNETWORK_H
