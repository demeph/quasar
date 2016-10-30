#ifndef JEUIA_H
#define JEUIA_H

#include <QLCDNumber>
#include <memory>
#include "calculamath.h"
#include "iEtat.h"


class jeuIA
{
public:
    jeuIA(std::shared_ptr<QLCDNumber> lcd);
    ~jeuIA();
    void setDisplay(int i);
    void aPerdu();
    void aGagner();
    void jouer();
    void finirJeu();
    std::shared_ptr<jeuIA> getptr();



private:
    std::shared_ptr<QLCDNumber> lcd_;
    std::shared_ptr<calculMath> outilsMath;
    std::shared_ptr<iEtat> jouer_;
    std::shared_ptr<iEtat> perdu_;
    std::shared_ptr<iEtat> gagne_;
    std::shared_ptr<iEtat> finirJeu_;

};

#endif // JEUIA_H
