#include "bautura.h"

// Implementarea clasei VinSticla

void VinSticla::printBautura(){
    std::cout << "-- Vin la Sticla --" << std::endl;
    std::cout << "Denumire: " << denumire << " --- " << pret << " RON" << std::endl;
    if(tip == true){
        std::cout<< "An Productie:" << an_productie << " Vin Rosu" << std::endl;
    }else{
        std::cout<< "An Productie:" << an_productie << " Vin Alb" << std::endl;
    }
}

std::istream & operator >> (std::istream &in, VinSticla &prod){
    std::cout << "Pretul:" << std::endl;
    in >> prod.pret;
    try{
        if(prod.pret <= 0)
            throw prod.pret;
    }catch(double x){
        prod.pret = 10;
        std::cout << "Pretul nu poate fi negativ, se va seta acesta la valoarea 10!" << std::endl;
    }
    std::cout << "An Productie:" << std::endl;
    in >> prod.an_productie;
    std::cout << "Denumire:" << std::endl;
    in >> prod.denumire;
    std::cout << "Tip: (0 - alb, 1 - rosu)" << std::endl;
    in >> prod.tip;
    return in;
}

std::ostream & operator << (std::ostream &out, VinSticla &prod){
    out << "-- Vin la Sticla --" << std::endl;
    out << "Denumire: " << prod.denumire << " --- " << prod.pret << " RON" << std::endl;
    if(prod.tip == true){
        out<< "An Productie:" << prod.an_productie << " Vin Rosu" << std::endl;
    }else{
        out<< "An Productie:" << prod.an_productie << " Vin Alb" << std::endl;
    }
    return out;
}

VinSticla & VinSticla::operator = (const VinSticla &other){
    if(this != &other){
        pret = other.pret;
        tip = other.tip;
        an_productie = other.an_productie;
        denumire = other.denumire;
    }
    return *this;
}

VinSticla::VinSticla(const VinSticla &other){
    pret = other.pret;
    tip = other.tip;
    an_productie = other.an_productie;
    denumire = other.denumire;
}

// Implementarea clasei VinPahar

void VinPahar::printBautura(){
    std::cout << "-- Vin la Pahar --" << std::endl; 
    std::cout << "Denumire: " << denumire << " --- " << pret << " RON" << std::endl;
    if(tip == true){
        std::cout << "Vin Rosu" << std::endl;
    }else{
        std::cout << "Vin Alb" << std::endl; 
    }
}

std::istream & operator >> (std::istream & in, VinPahar & prod){
    std::cout << "Pretul: " << std::endl;
    in >> prod.pret;
    try{
        if(prod.pret <= 0)
            throw prod.pret;
    }catch(double x){
        prod.pret = 10;
        std::cout << "Pretul nu poate fi negativ, se va seta acesta la valoarea 10!" << std::endl;
    }
    std::cout << "Vin Rosu sau alb (0 - alb, 1 - rosu)" << std::endl;
    in >> prod.tip;
    return in;
}

std::ostream & operator << (std::ostream & out, VinPahar & prod){
    out << "-- Vin la Pahar --" << std::endl; 
    out << "Denumire: " << prod.denumire << " --- " << prod.pret << " RON" << std::endl;
    if(prod.tip == true){
        out << "Vin Rosu" << std::endl;
    }else{
        out << "Vin Alb" << std::endl; 
    }
    return out;
}

VinPahar & VinPahar::operator = (const VinPahar & other){
    if(this != &other){
        pret = other.pret;
        tip = other.tip;
    }
    return *this;
}

VinPahar::VinPahar(const VinPahar & other){
    tip = other.tip;
    pret = other.pret;
}

// Implementarea clasei Bere

void Bere::printBautura(){
    std::cout << "-- Bere --" << std::endl;
    std::cout << "Denumire: " << denumire << " --- " << pret << " RON" << std::endl;
    if(alcool == true){
        std::cout << "Bere cu alcool" << std::endl;
    }else{
        std::cout << "Bere fara alcool" << std::endl;
    }
}

std::ostream & operator << (std::ostream &out, Bere &prod){
    out << "-- Bere --" << std::endl;
    out << "Denumire: " << prod.denumire << " --- " << prod.pret << " RON" << std::endl;
    if(prod.alcool == true){
        out << "Bere cu alcool" << std::endl;
    }else{
        out << "Bere fara alcool" << std::endl;
    }
    return out;
}

std::istream & operator >> (std::istream &in, Bere &prod){
    std::cout << "Denumire: ";
    in >> prod.denumire;
    std::cout << "Pret:" << std::endl;
    in >> prod.pret;
    try{
        if(prod.pret <= 0)
            throw prod.pret;
    }catch(double x){
        prod.pret = 10;
        std::cout << "Pretul nu poate fi negativ, se va seta acesta la valoarea 10!" << std::endl;
    }
    std::cout << "Cu Alcool sau fara (0 - fara alcool, 1 - cu alcool)" << std::endl;
    in >> prod.alcool;
    return in;
}

Bere & Bere::operator = (const Bere &other){
    if(this != &other){
        pret = other.pret;
        alcool = other.alcool;
    }
    return *this;
}

Bere::Bere(const Bere & other){
    denumire = other.denumire;
    pret = other.pret;
    alcool = other.alcool;
}

// Implementarea clasei Apa

void Apa::printBautura(){
    std::cout << "-- Apa --" << std::endl;
    std::cout << "Denumire: " << denumire << " --- " << pret << "RON" << std::endl;
    if(carbogazoasa == true){
        std::cout << "Apa Carbogazoasa" << std::endl;
    }else{
        std::cout << "Apa Plata" << std::endl;
    }
}

std::istream & operator >>(std::istream &in, Apa &prod){
    std::cout << "Denumire:";
    in >> prod.denumire;
    std::cout << "Pret: ";
    in >> prod.pret;
    try{
        if(prod.pret <= 0)
            throw prod.pret;
    }catch(double x){
        prod.pret = 10;
        std::cout << "Pretul nu poate fi negativ, se va seta acesta la valoarea 10!" << std::endl;
    }
    std::cout << "Tipul apei(0 - plata, 1 - carbogazoasa): ";
    in >> prod.carbogazoasa;
    return in;
}

std::ostream & operator <<(std::ostream &out, Apa &prod){
    out << "-- Apa --" << std::endl;
    out << "Denumire: " << prod.denumire << " --- " << prod.pret << "RON" << std::endl;
    if(prod.carbogazoasa == true){
        out << "Apa Carbogazoasa" << std::endl;
    }else{
        out << "Apa Plata" << std::endl;
    }
    return out;
}

Apa & Apa::operator = (const Apa &other){
    if(this != &other){
        denumire = other.denumire;
        pret = other.pret;
        carbogazoasa = other.carbogazoasa;
    }
    return *this;
}

Apa::Apa(const Apa &other){
    denumire = other.denumire;
    pret = other.pret;
    carbogazoasa = other.carbogazoasa;
}

Bautura::Bautura(const Bautura &other){
    pret = other.pret;
    denumire = other.denumire;
}