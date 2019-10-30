#ifndef VECTORGRAF_H
#define VECTORGRAF_H

#include "graf_ponderat.h"

class vectorGraf{
    int length;
    friend class Graf_ponderat;
    Graf_ponderat *vectorGrafPonderat;
public:
    vectorGraf();
    vectorGraf(int);
    int getLength(){return length;}
    friend std::ostream & operator <<(std::ostream &, vectorGraf &);
    friend std::istream & operator >>(std::istream &, vectorGraf &);
    ~vectorGraf();
};
#endif