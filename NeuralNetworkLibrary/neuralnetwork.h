#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include "layer.h"
#include "QList"

class NeuralNetwork
{
public:
    NeuralNetwork();
private:
    QList<Layer*> layers;
};

#endif // NEURALNETWORK_H
