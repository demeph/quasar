#include "jeu.h"
#include "ModeMenu.h"
#include "modeordi.h"
#include "modejoueur.h"

Jeu::Jeu()
{
    setFixedSize(260,260);

    leswidgets_ = std::shared_ptr<QStackedWidget>(new QStackedWidget(this));
    leswidgets_->addWidget(new modeMenu(this));
    leswidgets_->addWidget(new modeHumain(this));
    leswidgets_->addWidget(new modeOrdi(this));
    layout_ = std::shared_ptr<QVBoxLayout>(new QVBoxLayout());
    layout_->addWidget(leswidgets_.get());
    setLayout(layout_.get());
}

Jeu::~Jeu()
{

}
