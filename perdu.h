#ifndef PERDU_H
#define PERDU_H
#include <memory>
#include "iEtat.h"
#include "modeordi.h"

class Perdu : public iEtat
{
public:
    Perdu(const std::shared_ptr<modeOrdi> &ia);
    ~Perdu();
    void action();
    std::string getInfo();

private:
    std::shared_ptr<modeOrdi> ia_;
    std::string info_;

};

#endif // PERDU_H
