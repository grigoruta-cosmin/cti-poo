#include "restaurant.h"

Restaurant::Restaurant() : numarulDeMese(0), nume(""){}

Restaurant::Restaurant(int numarulDeMese, std::string nume) : numarulDeMese(numarulDeMese), nume(nume) {}

// de implementat daca nu pot fi adaugati clientii la masa!!!

void Restaurant::intraClienti(int numarClienti){
    bool flag = false;
    for(int i = 0; i < numarulDeMese; i++)
        if(numarClienti <= vectorMese[i].get_maximLocuri()){
            flag = true;
            for(int j = 0; j < numarClienti; j++)
                vectorMese[i].adaugaClient();
            break;
        }
    if(flag == false){
        std::cout << "Numarul de clienti este prea mare pentru o a fi asezati la o masa!" << std::endl;
    }
}

void Restaurant::afisMeseOcupate(){
    for(int i = 0; i < numarulDeMese; i++)
        if(vectorMese[i].masaGoala() == false){
            std::cout << "Masa " << i + 1 << " are " << vectorMese[i].get_locuriOcupate() << " clienti." << std::endl;
        }
}

void Restaurant::notaToataMasa(int indexMasa){
    if(vectorMese[indexMasa - 1].masaGoala() == true){
        std::cout << "Masa este goala" << std::endl;
    }else{
        vectorMese[indexMasa - 1].notaPentruToataMasa();
    }
}

void Restaurant::obtineComanda(int indexMasa){
//indexMasa -1 pentru ca in afisare messele au id-ul i + 1
    vectorMese[indexMasa - 1].seteazaMeniu(meniuRestaurant);
    if(vectorMese[indexMasa - 1].masaGoala() == true){
        std::cout << "Masa " << indexMasa << " este goala!" << std::endl;
    }else{
        vectorMese[indexMasa - 1].cereComanda();
    }
}

void Restaurant::clientPleaca(int indexMasa){
//indexMasa - 1 pentru ca in afisare mesele au id-ul i + 1
    if(vectorMese[indexMasa - 1].masaGoala() == true){
        std::cout << "Masa " << indexMasa << " este goala!" << std::endl;
    }else{
        vectorMese[indexMasa - 1].pleacaClient();
    }
}

std::istream & operator >>(std::istream & in, Restaurant & prod){
    std::cout << "Numele Restaurantului:" << std::endl;
    in >> prod.nume;
    std::cout << "Se citeste meniul restaurantului:" << std::endl;
    in >> prod.meniuRestaurant;
    std::cout << "Se citeste numarul de mese:" << std::endl;
    in >> prod.numarulDeMese;
    std::cout << "Se citesc mesele..." << std::endl;
    for(int i = 0; i < prod.numarulDeMese; i++)
        prod.vectorMese.push_back(Masa());
    for(int i = 0; i < prod.numarulDeMese; i++)
        in >> prod.vectorMese[i];
    return in;
}

std::ostream & operator<<(std::ostream &out, Restaurant &prod){
    out << "Nume Restaurant: " << prod.nume << std::endl;
    out << "Meniu: " << prod.meniuRestaurant << std::endl;
    return out; 
}