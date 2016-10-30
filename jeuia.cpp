#include "jeuia.h"
#include "jouer.h"
#include "gagne.h"
#include "perdu.h"
#include "arret.h"

jeuIA::jeuIA(std::shared_ptr<QLCDNumber> lcd)
{
    lcd_ = lcd;
    lcd_->setSegmentStyle(QLCDNumber::Flat);
    lcd_->move(70,50);
    lcd_->display(1);
    lcd_->setFixedSize(100,40);
    lcd_->display(1);

}


jeuIA::~jeuIA()
{

}

void jeuIA::setDisplay(int i)
{
    lcd_->display(i);
}

void jeuIA::jouer()
{
    //std::shared_ptr<iEtat> jouer(getptr());
    jouer_ = std::shared_ptr<iEtat>(new Jouer(getptr()));
    jouer_->jouer();
}

void jeuIA::aGagner()
{

}

void jeuIA::aPerdu()
{

}

std::shared_ptr<jeuIA> jeuIA::getptr()
{
    return std::shared_ptr<jeuIA>(this);
}

void jeuIA::finirJeu()
{

}
