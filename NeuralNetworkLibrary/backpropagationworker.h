#ifndef BACKPROPAGATIONWORKER_H
#define BACKPROPAGATIONWORKER_H

#include <QObject>

class BackpropagationWorker : public QObject {
Q_OBJECT
public:
    explicit BackpropagationWorker(QObject *parent = nullptr);

signals:

};

#endif // BACKPROPAGATIONWORKER_H
