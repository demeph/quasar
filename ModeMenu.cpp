#include "ModeMenu.h"
#include <QApplication>

modeMenu::modeMenu(QWidget *parent) : QWidget(parent)
{
    //setFixedSize(250,250);
    modeJoueur = std::shared_ptr<QPushButton>(new QPushButton("ModeJoueur",this));
    modeJoueur->setToolTip("Choissisez la mode humain");
    modeJoueur->move(55,70);
    modeJoueur->setFixedSize(100,30);

    modeIA = std::shared_ptr<QPushButton>(new QPushButton("Mode IA",this));
    modeIA->setToolTip("Choisissez la mode Ordinateur");
    modeIA->move(55,120);
    modeIA->setFixedSize(100,30);

    std::shared_ptr<QPushButton> menu1(new QPushButton("Menu",parent));
    menu = menu1;
    menu->move(0,0);
    menu->hide();
    menu->setFixedSize(80,20);

    connect(modeJoueur.get(),SIGNAL(clicked()),this,SLOT(on_modeJoueur_clicked()));
    connect(modeIA.get(),SIGNAL(clicked()),this,SLOT(on_modeIA_clicked()));
    connect(menu.get(),SIGNAL(clicked()),this,SLOT(on_menu_clicked()));

    ia = std::shared_ptr<modeOrdi>(new modeOrdi(this));
    modeJ = std::shared_ptr<modeHumain>(new modeHumain(this));

    modeJ->hide();
    ia->hide();

    modeJoueur->show();
    modeIA->show();

}

modeMenu::~modeMenu()
{

}

void modeMenu::on_modeJoueur_clicked()
{
    modeJ->show();
    modeJ->cacherArretJeu();
    menu->show();
    modeJoueur->hide();
    modeIA->hide();
}

void modeMenu::on_modeIA_clicked()
{
    menu->show();
    modeIA->hide();
    modeJoueur->hide();
    ia->show();
}

void modeMenu::on_menu_clicked()
{
    if (ia)
    {
      ia->hide();
      ia->resetJeu();
      //ia.reset();
    }
    if (modeJ)
    {
      modeJ->hide();
      //modeJ.reset();
    }
    modeIA->show();
    modeJoueur->show();
    menu->hide();
}
