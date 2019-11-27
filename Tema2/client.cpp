#include "client.h"

void Client::citesteMeniu(Meniu &other){
    comandaProprie.setMeniu(other);
}

void Client::comanda(){
    comandaProprie.setComanda();
    comandaProprie.calculeazaNota();
    notaProprie = comandaProprie.get_notaDePlata();
}

void Client::afiseazaComandaClientului(){
    comandaProprie.afiseazaComanda();
}

void Client::nota(){
    std::cout << comandaProprie << std::endl;
    notaProprie = comandaProprie.get_notaDePlata();
}

Client & Client::operator=(const Client &other){
    notaProprie = other.notaProprie;
    comandaProprie = other.comandaProprie;
}

std::ostream & operator<<(std::ostream &out, Client &prod){
    prod.comandaProprie.afiseazaComanda();
    prod.notaProprie = prod.comandaProprie.get_notaDePlata();
    out << "<---! NOTA !--->" << std::endl;
    out << "     " << prod.notaProprie << std::endl;
    return out;
}

std::istream & operator >>(std::istream &in, Client &prod){
    std::cout << "Se citeste comanda" << std::endl;
    in >> prod.comandaProprie;
    std::cout << "Se citeste nota " << std::endl;
    in >> prod.notaProprie;
    return in;
}