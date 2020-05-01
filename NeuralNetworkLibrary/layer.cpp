#include "layer.h"

Layer::Layer(int inputs, int outputs) {

    // Initialization...
    weights = new QVector<QVector<double>>();
    biases = new QVector<double>();

    // Populate 2D weights array with random values.
    for (int i = 0; i < inputs; ++i) {
        QVector<double> tVect;
        for (int j = 0; j < outputs; ++j) {
            tVect.push_back(qSqrt(-2*qLn(qrand()))*(qRound((double)qrand()) == 1?-1:1)*(1/qSqrt(inputs*outputs)));
        }
        weights->push_back(tVect);
    }

    // Same randomization process for biases.
    for (int k = 0; k < outputs; ++k) {
        biases->push_back(qSqrt(-2*qLn(qrand()))*(qRound((double)qrand()) == 1?-1:1)*(1/qSqrt(inputs*outputs)));
    }

}
