#ifndef CLIENT_H
#define CLIENT_H

#include "comanda.h"

class Client{
    double notaProprie;
    Comanda comandaProprie;
public:
    Client(double notaProprie = 0) : notaProprie(notaProprie){}
    void comanda();
    void nota();
    void citesteMeniu(Meniu &);
    void afiseazaComandaClientului();
    double get_notaProprie() const {return notaProprie;}
    Client & operator=(const Client &);
    friend std::istream & operator>>(std::istream &, Client &);
    friend std::ostream & operator<<(std::ostream &, Client &);
    ~Client() = default;
};

#endif