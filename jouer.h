#ifndef JOUER_H
#define JOUER_H
#include <memory>

#include "calculamath.h"
#include "iEtat.h"
#include "modeordi.h"


class Jouer: public iEtat
{
public:
    Jouer(const std::shared_ptr<modeOrdi> &ia);
    ~Jouer();
    void action();
    std::string getInfo(){return "";}

private:

    std::shared_ptr<modeOrdi> ia_;
    std::shared_ptr<calculMath> outilsMath;

};

#endif // JOUER_H
