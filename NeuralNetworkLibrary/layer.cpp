#include "layer.h"

Layer::Layer(int inputs, int outputs)
{
    const int inp{inputs};
    const int outp{outputs};

    weights = new double[inp][outp];
}
