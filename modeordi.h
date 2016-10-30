#ifndef MODEORDI_H
#define MODEORDI_H

#include <memory>
#include <QLabel>
#include <QLCDNumber>
#include <QObject>
#include <QPushButton>
#include <QSpinBox>
#include <QTimer>
#include <QWidget>
#include "enumetat.h"
#include "iEtat.h"
#include "jeuia.h"

class modeOrdi :public QWidget
{
    Q_OBJECT
public:
    explicit modeOrdi(QWidget *parent = 0);
    ~modeOrdi();
    int getNbPArtie();
    int getScore();
    void setNbParties();
    void setScore(int score);
    void setArretJeu(bool val);
    void setPeutJouer(bool val);
    void recommencerJeu();
    void resetJeu();
    void evaluerScore();

    /*void aPerdu();
    void aGagner();*/

private:
    std::shared_ptr<QSpinBox> nbParties_;
    std::shared_ptr<QPushButton> validerNbParties_;
    std::shared_ptr<QLCDNumber> lcdEcran_;
    std::shared_ptr<QLabel> label_;
    std::shared_ptr<iEtat> etat_;   //etatCourant
    std::shared_ptr<iEtat> jouer_;
    std::shared_ptr<iEtat> perdu_;
    std::shared_ptr<iEtat> gagne_;

    std::vector<std::shared_ptr<QLabel>> lesLabels;

    std::shared_ptr<QTimer> temps_;
    int score_, nbTours_;
    bool peutJouer, arretJeu;

signals:

public slots:
    void play();
    void update();

};

#endif // MODEORDI_H
