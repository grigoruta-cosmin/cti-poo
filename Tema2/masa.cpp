#include "masa.h"

Masa::Masa() : maximLocuri(0), notaMesei(0), locuriOcupate(0){}

Masa::Masa(int countClienti, int maximLocuri, int locuriOcupate, double notaMesei) : maximLocuri(maximLocuri), notaMesei(notaMesei), locuriOcupate(locuriOcupate){}

void Masa::seteazaMeniu(Meniu &meniu){
    for(int i = 0; i < vectorClienti.size(); i++)
        vectorClienti[i].citesteMeniu(meniu);
}

double Masa::calculeazaNotaMesei() const {
    double ans = 0;
    for(int i = 0; i < vectorClienti.size(); i++)
        ans += vectorClienti[i].get_notaProprie();
    return ans;
}

void Masa::adaugaClient(){
    locuriOcupate++;
    vectorClienti.push_back(Client());
}

bool Masa::masaGoala(){
    if(vectorClienti.size() == 0)
        return true;
    else
        return false;
}

void Masa::notaPentruToataMasa(){
    double prevNotaMesei = notaMesei;
    int len = vectorClienti.size();
    for(int i = 0; i < len; i++)
        pleacaClient();
    std::cout << "<---!!! Nota Mesei !!!--->" << std::endl;
    std::cout << "        " << prevNotaMesei << std::endl;
    vectorClienti.clear();
}

void Masa::cereComanda(){
    for(int i = 0; i < vectorClienti.size(); i++)
        vectorClienti[i].comanda();
    notaMesei = calculeazaNotaMesei();
}

void Masa::pleacaClient(){
    vectorClienti[vectorClienti.size() - 1].nota();
    notaMesei -= vectorClienti[vectorClienti.size() - 1].get_notaProprie();
    vectorClienti.pop_back();
    locuriOcupate--;
}

void Masa::printComandaActuala(){
    for(int i = 0; i < vectorClienti.size(); i++)
        vectorClienti[i].afiseazaComandaClientului();
}

std::istream & operator>>(std::istream & in, Masa &prod){
    std::cout << "Se citesc caracteristicile mesei " << std::endl;
    in >> prod.maximLocuri;
    return in;
}


std::ostream & operator<<(std::ostream &out, Masa &prod){
    if(prod.vectorClienti.size() == 0){
        out << "Masa este goala!" << std::endl;
    }else{
        out << "La masa se afla urmatoarele comenzi" << std::endl;
        prod.printComandaActuala();
    }
    return out;
}

Masa & Masa::operator=(const Masa &other){
    locuriOcupate = other.locuriOcupate;
    maximLocuri = other.maximLocuri;
    notaMesei = other.notaMesei;
    vectorClienti = other.vectorClienti;
}