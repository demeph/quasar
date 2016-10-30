#include "calculamath.h"

calculMath::calculMath()
{

}

calculMath::~calculMath()
{

}

int calculMath::nbAleatUnHuit()
{
    std::srand(std::time(0));
    return 1 + (std::rand()%8);
}

int calculMath::nbAleat47()
{
    std::srand(std::time(0));
    return  4 + (std::rand()%4);
}

int calculMath::nbAleat(int i)
{
    std::srand(std::time(0));
    return (std::rand() % i);
}
