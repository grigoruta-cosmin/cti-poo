#ifndef MASA_H
#define MASA_H

#include "client.h"
/* De implementat clasa masa */

class Masa{
    int locuriOcupate;
    int maximLocuri;
    double notaMesei;
    std::vector<Client> vectorClienti;
public:
    Masa();
    Masa(int, int, int, double);
    void seteazaMeniu(Meniu &meniu);
    void cereComanda();
    void afiseazaComandaMesei();
    void notaPentruToataMasa();
    void printComandaActuala();
    int get_locuriOcupate() const {return locuriOcupate;}
    int get_maximLocuri() const {return maximLocuri;}
    double get_notaMesei() const {return notaMesei;}
    double calculeazaNotaMesei() const;
    void adaugaClient();
    void pleacaClient();
    bool masaGoala();
    Masa & operator= (const Masa &);
    friend std::istream & operator>>(std::istream &, Masa &);
    friend std::ostream & operator<<(std::ostream &, Masa &);
    ~Masa() = default;
};

#endif