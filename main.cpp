#include <QtGui>
#include <QApplication>
#include <QIcon>
#include <memory>
#include "jeu.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    Jeu jeu;
    QIcon icon("Q.png");
    jeu.setWindowIcon(icon);
    jeu.setWindowTitle("Jeu Quasar");
    jeu.show();

    return app.exec();
}
