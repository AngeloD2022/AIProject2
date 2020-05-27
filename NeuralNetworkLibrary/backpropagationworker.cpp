#include "backpropagationworker.h"

BackpropagationWorker::BackpropagationWorker(QObject *parent) : QObject(parent) {

}

void BackpropagationWorker::doBackpropagation(QList<double> &de2dy, QList<Layer> &layers) {

    QList<double> layerOutputDeltas = de2dy;

    // How each input effects the cost function...
    QList<double> de2da;

    // For each layer in layers
    // Starting at the end, of course.
    for (int layer = layers.length() - 1; layer >= 0; --layer) {

    }
}
