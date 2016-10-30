#ifndef MODEJOUEUR_H
#define MODEJOUEUR_H

#include <memory>
#include <QObject>
#include <iostream>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLCDNumber>
#include <QMessageBox>
#include <QString>
#include "iCommand.h"
#include "enumtype.h"
#include "fabriqueSimple.h"
#include "joueur.h"

class modeHumain : public QWidget
{
    Q_OBJECT
public:
    explicit modeHumain(QWidget *parent = 0);
    ~modeHumain();
    void cacherArretJeu();

signals:

public slots:
    void on_clicked(TypeNombre typeNb);
    void on_arreterJeu_clicked();

private:
    std::string gainChaine[7] = {"5","10","20","25","30","40","0"};
    int gain[7] = {5,10,20,25,30,40,0};

    //des attribut necessaire pour mode Joueur
    std::shared_ptr<QPushButton> nbUnAHuit_;
    std::shared_ptr<QPushButton> nbQuatreASept_;
    std::shared_ptr<QLCDNumber> lcdEcran_;
    std::shared_ptr<iCommand> cmd_;
    std::shared_ptr<QPushButton> arreterJeu;
    std::shared_ptr<Joueur> j;
    std::shared_ptr<QLabel> lbl_;
    std::shared_ptr<QLabel> lbl1_;

    std::shared_ptr<fabriqueNombre> fabriqueNb;

    bool aQuinzePoint;
    void evalueScore(int nb);
    void playEngine(std::shared_ptr<iCommand> cmd);
    void recommencerJeu();
    void perdu();
    void gagne();
    void afficherMessage(std::string msg);
    int balance;



};

#endif // MODEJOUEUR_H
