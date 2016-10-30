#include "gagne.h"

Gagne::Gagne(const std::shared_ptr<modeOrdi> &ia)
{
    ia_ = ia;
    info_ = "IA a gagné.";
}

Gagne::~Gagne()
{

}

std::string Gagne::getInfo()
{
    return info_;
}

void Gagne::action()
{
    ia_->setPeutJouer(false);
}
