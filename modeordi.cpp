#include "modeordi.h"
#include "jouer.h"
#include "gagne.h"
#include "perdu.h"

modeOrdi::modeOrdi(QWidget *parent) : QWidget(parent)
{
    score_ = 1;
    nbTours_ = 0;
    peutJouer = true;
    arretJeu = false;

    nbParties_ = std::shared_ptr<QSpinBox>(new QSpinBox(this));
    nbParties_ -> move(100,165);
    nbParties_ -> setRange(1,5);
    nbParties_ -> show();

    validerNbParties_ = std::shared_ptr<QPushButton>(new QPushButton("Jouer",this));
    validerNbParties_ -> setToolTip("Commencer le jeu d'Ordi");
    validerNbParties_ -> move(80,195);
    validerNbParties_ -> show();

    lcdEcran_ = std::shared_ptr<QLCDNumber>(new QLCDNumber(this));
    lcdEcran_ -> setSegmentStyle(QLCDNumber::Flat);
    lcdEcran_ -> move(70,115);
    lcdEcran_ -> display(1);
    lcdEcran_ -> setFixedSize(100,50);

    connect(this->validerNbParties_.get(), &QPushButton::released, [=]{
        play();
    });

    jouer_ = std::shared_ptr<iEtat>(new Jouer(std::shared_ptr<modeOrdi>(this)));
    perdu_ = std::shared_ptr<iEtat>(new Perdu(std::shared_ptr<modeOrdi>(this)));
    gagne_ = std::shared_ptr<iEtat>(new Gagne(std::shared_ptr<modeOrdi>(this)));
    etat_ = jouer_;

    temps_ = std::shared_ptr<QTimer>(new QTimer(this));
    temps_->setSingleShot(false);

    connect(this->temps_.get(), &QTimer::timeout, [=]{
        update();
    });

    for(int i =0; i < 5; ++i)
    {
        label_ = std::shared_ptr<QLabel>(new QLabel(this));
        label_ -> setText("");
        label_ -> move(0,10+15*(i+1));
        label_ -> setFixedWidth(250);
        label_ -> show();
        lesLabels.push_back(label_);
    }
}

modeOrdi::~modeOrdi()
{

}

void modeOrdi::evaluerScore()
{
    if ( score_ > 20)
    {
        etat_ = perdu_;
    }
    else if (score_ == 20)
    {
        etat_ = gagne_;
    }
    else
    {
        if (arretJeu)
        {
            etat_ = gagne_;
        }
    }
}

void modeOrdi::update()
{
    if (nbTours_ < nbParties_->value())
    {
        etat_->action();
        lcdEcran_->display(score_);
        if (!(peutJouer))
        {
            std::string info_;
            nbTours_ += 1;
            info_ = info_ +"Partie " + std::to_string((nbTours_)) + " : "+ etat_->getInfo();
            info_ += " Score : " + std::to_string((int)lcdEcran_->value());
            lesLabels[nbTours_-1]->setText(QString::fromStdString(info_));
            recommencerJeu();
        }
    }
    else
    {
        temps_->stop();
    }
}

void modeOrdi::play()
{
    resetJeu();
    temps_->start(1000);
}

void modeOrdi::recommencerJeu()
{
    score_ = 1;
    peutJouer = true;
    arretJeu = false;
    lcdEcran_->display(score_);
    etat_ = jouer_;
    temps_->start();
}

void modeOrdi::resetJeu()
{
    score_ = 1;
    peutJouer = true;
    nbTours_ = 0;
    arretJeu = false;
    lcdEcran_->display(score_);
    for(int i = 0; i < 5; ++i)
    {
        lesLabels[i]->setText("");
    }
    etat_ = jouer_;
}

int modeOrdi::getScore()
{
    return score_;
}

int modeOrdi::getNbPArtie()
{
    return nbParties_->value();
}

void modeOrdi::setScore(int score)
{
    score_ +=score;
}

void modeOrdi::setPeutJouer(bool val)
{
    peutJouer = val;
}

void modeOrdi::setArretJeu(bool val)
{
    arretJeu = val;
}
