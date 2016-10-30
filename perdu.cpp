#include "perdu.h"

Perdu::Perdu(const std::shared_ptr<modeOrdi> &ia)
{
    ia_ = ia;
    info_ = "IA a perdu.";
}

Perdu::~Perdu()
{

}

std::string Perdu::getInfo()
{
    return info_;
}

void Perdu::action()
{
    ia_->setPeutJouer(false);
}
