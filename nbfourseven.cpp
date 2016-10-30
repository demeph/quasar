#include "nbfourseven.h"

nbFourSeven::nbFourSeven()
{
    std::shared_ptr<calculMath> math1(new calculMath());
    outilsMath = math1;
}

nbFourSeven::~nbFourSeven()
{

}

int nbFourSeven::execute()
{
    return outilsMath->nbAleat47();
}
