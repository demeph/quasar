#ifndef ARRET_H
#define ARRET_H
#include <memory>
#include "iEtat.h"
#include "jeuia.h"

class Arret :public iEtat
{
public:
    Arret();
    ~Arret();
    void aPerdu();
    void aGagner();
    void jouer();
    void finirJeu();
private:
    std::shared_ptr<jeuIA> ia_;
};

#endif // ARRET_H
