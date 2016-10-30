#include "modejoueur.h"


modeHumain::modeHumain(QWidget *parent) : QWidget(parent)
{
    aQuinzePoint = false;

    nbUnAHuit_ = std::shared_ptr<QPushButton>(new QPushButton("1  à  8",this));
    nbUnAHuit_->setToolTip("Nombre Aleatoire entre 1 à 8");
    nbUnAHuit_->move(30,130);

    nbQuatreASept_ = std::shared_ptr<QPushButton>(new QPushButton("4  à  7",this));
    nbQuatreASept_->setToolTip("Nombre Aleatoire entre 4 à 7");
    nbQuatreASept_->move(140,130);

    lcdEcran_ = std::shared_ptr<QLCDNumber>(new QLCDNumber(this));
    lcdEcran_->setSegmentStyle(QLCDNumber::Flat);
    lcdEcran_->move(70,50);
    lcdEcran_->display(1);
    lcdEcran_->setFixedSize(100,40);    

    fabriqueNb = std::unique_ptr<fabriqueNombre>(new fabriqueNombre());

    nbQuatreASept_->show();
    nbUnAHuit_->show();

    arreterJeu = std::shared_ptr<QPushButton>(new QPushButton("Arreter le partie",this));
    arreterJeu->move(70,160);

    connect(this->nbUnAHuit_.get(), &QPushButton::released, [=]{
        on_clicked(NbUnAHuit);
    });

    connect(this->nbQuatreASept_.get(), &QPushButton::released, [=]{
        on_clicked(NbQuatreASept);
    });

    QObject::connect(arreterJeu.get(),SIGNAL(clicked()),this,SLOT(on_arreterJeu_clicked()));

    j = std::shared_ptr<Joueur>(new Joueur("Demetre"));

    balance = j->getBalance();
    std::string msg = "Bonjour " + j->getNom();

    lbl_ = std::shared_ptr<QLabel>(new QLabel(this));
    lbl_->setText(QString::fromStdString(msg));
    lbl_->move(0,10);
    lbl_->show();

    lbl1_ = std::shared_ptr<QLabel>(new QLabel(this));
    std::string st = "votre balanece : ";
    st += std::to_string(j->getBalance());
    st += " €";
    lbl1_->setText(QString::fromStdString(st));
    lbl1_->setFixedSize(250,13);
    lbl1_->move(0,30);
    lbl1_->show();

}

modeHumain::~modeHumain()
{

}

void modeHumain::evalueScore(int nb)
{
    if ( nb > 20 )
    {
        perdu();
    }
    else if ( nb == 20 )
    {
        gagne();
    }
    else if ((nb > 14) && (aQuinzePoint==false))
    {
        arreterJeu->show();
        aQuinzePoint =true;
    }
}

void modeHumain::afficherMessage(std::string msg)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Felicitation",QString::fromStdString(msg),QMessageBox::Yes|QMessageBox::No);

    if ( reply==QMessageBox::Yes)
    {
        recommencerJeu();
    } else {
        lcdEcran_->hide();
        nbUnAHuit_->hide();
        nbQuatreASept_->hide();
        arreterJeu->hide();
        lbl_->hide();
        lbl1_->hide();
    }
}
void modeHumain::gagne()
{
    j->setBalance(40);
    std::string st = "votre balanece : ";
    st += std::to_string(j->getBalance());
    st += " €";
    lbl1_->setText(QString::fromStdString(st));
    std::string message= "Felicitations, vous avez gagne la partie!!!\n ";
    message += "votre gaine est : 40 €";
    message += "\nVoulez-vous jouer a nouveau?";
    message +="\nOui - pour recommencer\nNo - menu principale";
    afficherMessage(message);
}

void modeHumain::perdu()
{
    std::string message= "Malheuresement vous avez perdu";
    message += "\nVoulez-vous jouer a nouveau?";
    message +="\nOui - pour recommencer\nNo - menu principale";
    afficherMessage(message);
}



void modeHumain::playEngine(std::shared_ptr<iCommand> cmd)
{
    int nb = cmd->execute();
    nb += j->getScore();
    j->setScore(nb);
    lcdEcran_->display(nb);
    evalueScore(nb);
}

void modeHumain::on_clicked(TypeNombre typeNb)
{
    cmd_ = fabriqueNb->createNb(typeNb);
    playEngine(cmd_);
}

void modeHumain::on_arreterJeu_clicked()
{
    int gainJoueur = j->getScore();
    std::string message= "Felicitations, vous avez gagne la partie!!!\n votre gaine est : ";
    gainJoueur -=15;
    j->setBalance(gain[gainJoueur]);
    std::string st = "votre balanece : ";
    st += std::to_string(j->getBalance());
    st += " €";
    lbl1_->setText(QString::fromStdString(st));
    message += gainChaine[gainJoueur];
    message += " €";
    message += "\nVoulez-vous jouer a nouveau?";
    message +="\nOui - pour recommencer\nNo - menu principale";
    afficherMessage(message);
}

void modeHumain::cacherArretJeu()
{
    arreterJeu->hide();
}

void modeHumain::recommencerJeu()
{
    aQuinzePoint = false;
    j -> recommencerJeu();
    lcdEcran_->display(1);
    arreterJeu->hide();
}
