#ifndef FABRIQUENOMBRE_H
#define FABRIQUENOMBRE_H

#include <memory>
#include "enumtype.h"
#include "iCommand.h"

class fabriqueNombre
{
public:
    fabriqueNombre();
    ~fabriqueNombre();
    std::shared_ptr<iCommand> createNb(TypeNombre typeNb);
};

#endif // FABRIQUENOMBRE_H
