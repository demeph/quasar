#include "fabriqueSimple.h"
#include "nbfourseven.h"
#include "nbunhuit.h"

fabriqueNombre::fabriqueNombre()
{

}


fabriqueNombre::~fabriqueNombre()
{

}

std::shared_ptr<iCommand> fabriqueNombre::createNb(TypeNombre typeNb)
{
    std::shared_ptr<iCommand> cmd;
    if (typeNb == NbUnAHuit)
    {
        cmd = std::shared_ptr<iCommand>(new NbUnHuit());
    }
    else if (typeNb == NbQuatreASept)
    {
        cmd = std::shared_ptr<iCommand>(new nbFourSeven());
    }
    return cmd;
}
