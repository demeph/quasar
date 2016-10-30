#ifndef NBUNHUIT_H
#define NBUNHUIT_H

#include <memory>
#include "iCommand.h"
#include "calculamath.h"

class NbUnHuit : public iCommand
{
public:
    NbUnHuit();
    ~NbUnHuit();
private:
    std::shared_ptr<calculMath> outilsMath;
    int execute();
};

#endif // NBUNHUIT_H
