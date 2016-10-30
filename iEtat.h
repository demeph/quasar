#ifndef IETAT_H
#define IETAT_H

class iEtat
{
public:
    virtual void action() =0;
    virtual std::string getInfo()=0;
};

#endif // IETAT_H
