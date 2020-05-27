#ifndef BACKPROPAGATIONWORKER_H
#define BACKPROPAGATIONWORKER_H

#include <QObject>
#include "layer.h"
#include "calc.h"

class BackpropagationWorker : public QObject {
Q_OBJECT
public:
    explicit BackpropagationWorker(QObject *parent = nullptr);

public slots:

    void doBackpropagation(QList<double> &de2dy, QList<Layer> &layers);

signals:

    void backpropagationFinished(QList<Layer> result);

    void progressMade(float percentage);

};

#endif // BACKPROPAGATIONWORKER_H
