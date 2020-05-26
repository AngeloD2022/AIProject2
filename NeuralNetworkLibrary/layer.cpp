#include "layer.h"

/*!
 * Neuron Layer Class - Constructor
 * @param inputs - layer inputs
 * @param outputs - layer outputs
 */
Layer::Layer(int inputs, int outputs) {
    this->inputs = inputs;
    this->outputs = outputs;
    QRandomGenerator64 *rand = new QRandomGenerator64();

    // Populate 2D weights array with random values.
    for (int i = 0; i < inputs; ++i) {
        QVector<double> tVect;
        for (int j = 0; j < outputs; ++j) {
            tVect.push_back(
                    qSqrt(-2 * qLn(rand->generateDouble())) * (qRound((double) rand->generateDouble()) == 1 ? -1 : 1) *
                    (1 / qSqrt(inputs * outputs)));
        }
        weights.push_back(tVect);
    }
    // Same randomization process for biases.
    for (int k = 0; k < outputs; ++k) {
        biases.push_back(
                qSqrt(-2 * qLn(rand->generateDouble())) * (qRound((double) rand->generateDouble()) == 1 ? -1 : 1) *
                (1 / qSqrt(inputs * outputs)));
    }

}

/*!
 * Computes the activations of the current layer, given the activations of the previous.
 * Also known as "forward propagation."
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

QList<double> Layer::computeWeightedSums(QList<double> inputs) {

    QList<double> result;

    for (int i = 0; i < this->outputs; ++i) {
        double out = 0;
        for (int j = 0; j < this->inputs; ++j) {
            out += weights[j][i] * inputs[j];
        }
        result.append(out + biases[i]);
    }
    return result;
}


void Layer::backpropagate(QList<double> costDerivatives, QList<double> badInput, QList<double> myBadOutput,
                          double learnRate) {

    QList<double> myBadWeightedSums = computeWeightedSums(badInput);
    QList<double> mySigPrimes = Calc::sigmoidDerivative(myBadWeightedSums);

    for (int layerOutput = 0; layerOutput < outputs; ++layerOutput) {
        QList<double> gradientVector;

        double myBadActivation = myBadOutput[1][layerOutput];

        double myBadBias = biases[layerOutput];

        for (int layerInput = 0; layerInput < inputs; ++layerInput) {

            // Derivative of cost with respect to a weight:
            // bad input activation * sigmoidDerivative(weighted sum) *
            // derivative of cost with respect to the bad output activation

            weights[layerOutput][layerInput] -=
                    badInput[layerInput] * // Previous Activation
                    mySigPrimes[layerOutput] * // SigmoidPrime(weightedsum[layerOutput])
                    2 * costDerivatives[layerOutput] // 2(myBadOutput[layerOutput] - desiredOutput[layerOutput])
                    * learnRate;

        }

        // Because the derivative of the weighted sum with respect to bias = 1,
        // it is only necessary to include the last two terms.
        biases[layerOutput] -= mySigPrimes[layerOutput] * 2 * costDerivatives[layerOutput] * learnRate;

    }
}