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
    void randomize();
};

#endif // NEURALNETWORK_H
