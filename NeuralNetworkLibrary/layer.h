#ifndef LAYER_H
#define LAYER_H
#include "calc.h"

class Layer
{

public:
    Layer(int inputs, int outputs);

private:
    double* weights;
    double* biases;
};

#endif // LAYER_H
