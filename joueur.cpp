#include "joueur.h"

Joueur::Joueur(std::string nom)
{
    nomJ = nom;
    score_ = 1;
    balance = 20;
}

Joueur::~Joueur()
{

}

void Joueur::setScore(int score)
{
    score_ = score;
}

void Joueur::recommencerJeu()
{
    score_= 1;
}

int Joueur::getScore()
{
    return score_;
}

int Joueur::getBalance()
{
    return balance;
}

bool Joueur::aGagne()
{
    return (score_ == 20);
}

void Joueur::setBalance(int nb)
{
    balance += nb;
}

std::string Joueur::getNom()
{
    return nomJ;
}
