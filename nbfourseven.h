#ifndef NBFOURSEVEN_H
#define NBFOURSEVEN_H

#include <memory>
#include "iCommand.h"
#include "calculamath.h"

class nbFourSeven : public iCommand
{
public:
    nbFourSeven();
    ~nbFourSeven();
    int execute();
private:
    std::shared_ptr<calculMath> outilsMath;
};

#endif // NBFOURSEVEN_H
