#ifndef GAGNE_H
#define GAGNE_H
#include <memory>
#include "iEtat.h"
#include "modeordi.h"


class Gagne : public iEtat
{
public:
    Gagne(const std::shared_ptr<modeOrdi> &ia);
    ~Gagne();
    void action();
    std::string getInfo();

private:
    std::shared_ptr<modeOrdi> ia_;
    std::string info_;

};

#endif // GAGNE_H
