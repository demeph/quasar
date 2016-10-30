#include "jouer.h"
#include "enumetat.h"

Jouer::Jouer(const std::shared_ptr<modeOrdi> &ia)
{
    ia_ = ia;
    outilsMath = std::shared_ptr<calculMath>(new calculMath());
}

Jouer::~Jouer()
{

}


void Jouer::action()
{
    int score = ia_->getScore();
    int nbAleat,temp,temp1;
    //Si on a la possibilite d'arreter le jeu
    if ( score > 14 )
    {
        temp = outilsMath -> nbAleat(10);
        if (temp >= 5)
        {
            ia_ ->setArretJeu(true);
            ia_ ->setPeutJouer(false);
        }
        else
        {
            temp1 = outilsMath->nbAleat(5);
            if (temp1 > 2 )
            {
                nbAleat = outilsMath -> nbAleatUnHuit();
            }
            else
            {
                nbAleat = outilsMath -> nbAleat47();
            }
        }
    }
    else if (score < 8)
    {
        temp = outilsMath -> nbAleat(4);
        if (temp > 1)
        {
            nbAleat = outilsMath-> nbAleatUnHuit();
        }
        else
        {
            nbAleat = outilsMath -> nbAleat47();
        }
    }
    else if (score >= 8)
    {
        temp = outilsMath->nbAleat(2);
        if (temp == 0)
        {
            nbAleat = outilsMath-> nbAleatUnHuit();
        }
        else
        {
            nbAleat = outilsMath -> nbAleat47();
        }
    }
    ia_->setScore(nbAleat);
    ia_->evaluerScore();
}
