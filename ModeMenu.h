#ifndef MODEMENU_H
#define MODEMENU_H

#include <memory>
#include <QPushButton>
#include <QWidget>
#include <QLCDNumber>
#include <QObject>
#include <QSpinBox>
#include "modejoueur.h"
#include "modeordi.h"
#include "jeu.h"

class modeMenu :public QWidget
{
    Q_OBJECT
public:
    explicit modeMenu(QWidget *parent = 0);
    ~modeMenu();

signals:

public slots:
    void on_modeJoueur_clicked();
    void on_modeIA_clicked();
    void on_menu_clicked();

private:

    std::shared_ptr<QPushButton> modeJoueur;
    std::shared_ptr<QPushButton> modeIA;
    std::shared_ptr<QPushButton> menu;
    std::shared_ptr<Jeu> jeu;
    std::shared_ptr<modeHumain> modeJ;
    std::shared_ptr<modeOrdi> ia;

};

#endif // TEST_H
