#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>

class Joueur
{
public:
    Joueur(std::string nom);
    ~Joueur();
    void setScore(int score);
    int getScore();
    int getBalance();
    bool aGagne();
    void recommencerJeu();
    void payer();
    void setBalance(int nb);
    std::string getNom();

private:
    int score_;
    int balance;
    std::string nomJ;


};

#endif // JOUEUR_H
