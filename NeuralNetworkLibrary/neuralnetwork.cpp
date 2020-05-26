#include "neuralnetwork.h"

NeuralNetwork::NeuralNetwork(QList<int> configuration) {
    // Populate the layer list with given neuron/layer config.
    for (int i = 1; i < configuration.length(); i++) {
        layers.push_back(new Layer(configuration[i - 1], configuration[i]));
    }
}

void NeuralNetwork::backpropagate(QList<QList<double>> badActivations, QList<double> desiredOutput, double learnRate) {
    QList<double> newdesiredoutput;
    QList<double> costDerivatives;
    QList<double> gvect;
    // badActivations = network input + other layers
    for (int layer = layers.length() - 1; layer >= 0; --layer) {
        if (layer == layers.length() - 1) {
            costDerivatives = Calc::costDerivative(badActivations[layer + 1], desiredOutput);
        } else {
            costDerivatives = Calc::costDerivative(badActivations[layer + 1],
                                                   Calc::vectorAdd(gvect, badActivations[layer + 1]));
        }
        gvect = layers[layer]->backpropagate(costDerivatives, badActivations[layer], badActivations[layer + 1],
                                             learnRate);
    }

}

