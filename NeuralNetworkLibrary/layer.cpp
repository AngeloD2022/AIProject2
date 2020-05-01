#include "layer.h"

/*!
 * Neuron Layer Class - Constructor
 * @param inputs - layer inputs
 * @param outputs - layer outputs
 */
Layer::Layer(int inputs, int outputs) {
    this->inputs = inputs;
    this->outputs = outputs;

    // Populate 2D weights array with random values.
    for (int i = 0; i < inputs; ++i) {
        QVector<double> tVect;
        for (int j = 0; j < outputs; ++j) {
            tVect.push_back(qSqrt(-2 * qLn(qrand())) * (qRound((double) qrand()) == 1 ? -1 : 1) *
                            (1 / qSqrt(inputs * outputs)));
        }
        weights.push_back(tVect);
    }

    // Same randomization process for biases.
    for (int k = 0; k < outputs; ++k) {
        biases.push_back(
                qSqrt(-2 * qLn(qrand())) * (qRound((double) qrand()) == 1 ? -1 : 1) * (1 / qSqrt(inputs * outputs)));
    }

}

/*!
 * Computes the activations of the current layer, given the activations of the previous.
 * @param inputs - activations of previous layer.
 * @return calculated outputs.
 */
QVector<double> Layer::computeActivations(QVector<double> inputs) {

    QVector<double> result;

    for (int i = 0; i < this->outputs; ++i) {
        double out = 0;
        for (int j = 0; j < this->inputs; ++j) {
            out += weights[j][i] * inputs[j];
        }
        result.push_back(Calc::sigmoid(out + biases[i]));
    }
    return result;
}