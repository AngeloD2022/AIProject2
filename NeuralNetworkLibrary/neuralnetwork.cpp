#include "neuralnetwork.h"

NeuralNetwork::NeuralNetwork(int *configuration[])
{
    // Initialize the layer list
    layers = new QList<Layer*>();

    // Populate the layer list with given neuron/layer config.
    for(int i = 1; i < sizeof(&configuration)/sizeof(configuration); i++){
        layers->push_back(new Layer(*configuration[i-1],*configuration[i]));
    }

}
