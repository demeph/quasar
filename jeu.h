#ifndef JEU_H
#define JEU_H

#include <memory>
#include <QtGui>
#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>


class Jeu: public QWidget
{
public:
    Jeu();
    ~Jeu();

private:
    std::shared_ptr<QStackedWidget> leswidgets_;
    std::shared_ptr<QVBoxLayout> layout_;
};

#endif // JEU_H
