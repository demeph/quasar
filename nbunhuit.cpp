#include "nbunhuit.h"

NbUnHuit::NbUnHuit()
{
    std::shared_ptr<calculMath> math1(new calculMath());
    outilsMath = math1;
}

NbUnHuit::~NbUnHuit()
{

}

int NbUnHuit::execute()
{
    return outilsMath->nbAleatUnHuit();
}


