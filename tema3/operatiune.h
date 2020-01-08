#ifndef OPERATIUNE_H
#define OPERATIUNE_H
#include <bits/stdc++.h>

class Operatiune{
    std::string denumireOperatiune;
    double soldDupaOperatiune;
public:
    Operatiune() = default;
    Operatiune(std::string denumireOperatiune, double soldDupaOperatiune):denumireOperatiune(denumireOperatiune), soldDupaOperatiune(soldDupaOperatiune){}
    std::string getDenumireOperatiune() const { return denumireOperatiune; }
    void setDenumireOperatiune(std::string denOp){ denumireOperatiune = denOp; }
    double getSoldDupaOperatiune() const { return soldDupaOperatiune; }
    void setSoldDupaOperatiune(double soldNou) { soldDupaOperatiune = soldNou; }
    friend std::ostream & operator<<(std::ostream&, const Operatiune&); 
    ~Operatiune() = default;
};

inline std::ostream & operator<<(std::ostream &os, const Operatiune &other){
    os << other.denumireOperatiune << std::endl;
    os << "SOLD ACTUAL:" << other.soldDupaOperatiune << std::endl;
    return os;
}
#endif