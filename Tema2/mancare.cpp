#include "mancare.h"


Mancare::Mancare(const Mancare &other){
    pret = other.pret;
    denumire = other.denumire;
}

// Implementarea clasei Ciorba

void Ciorba::printPreparat(){
    std::cout << "-- Ciorba --" << std::endl;
    std::cout << "Denumire: " << denumire << " --- " << pret << " RON" << std::endl;
    if(ardei == true){
        std::cout << "Cu Ardei" << std::endl;
    }else{
        std::cout << "Fara Ardei" << std::endl;
    }
    if(smantana == true){
        std::cout << "Cu Smantana" << std::endl;
    }else{
        std::cout << "Fara Smantana" << std::endl;
    }
}

std::istream & operator >>(std::istream & in, Ciorba & prod){
    std::cout << "Denumire :" << std::endl;
    in >> prod.denumire;
    std::cout << "Pret: " << std::endl;
    in >> prod.pret;
    try{
        if(prod.pret <= 0)
            throw prod.pret;
    }catch(double x){
        prod.pret = 10;
        std::cout << "Pretul nu poate fi negativ, se va seta acesta la valoarea 10!" << std::endl;
    }
    return in; 
}

std::ostream & operator <<(std::ostream & out, Ciorba & prod){
    out << "-- Ciorba --" << std::endl;
    out << "Denumire: " << prod.denumire << " --- " << prod.pret << " RON" << std::endl;
    if(prod.ardei == true){
        out << "Cu Ardei" << std::endl;
    }else{
        out << "Fara Ardei" << std::endl;
    }
    if(prod.smantana == true){
        out << "Cu Smantana" << std::endl;
    }else{
        out << "Fara Smantana" << std::endl;
    }
    return out;
}

void Ciorba::set_ardei(bool ans){
    ardei = ans;
}

void Ciorba::set_smantana(bool ans){
    smantana = ans;
}


Ciorba & Ciorba::operator = (const Ciorba &other){
    if(this != &other){
        pret = other.pret;
        denumire = other.denumire;
        smantana = other.smantana;
        ardei = other.ardei;
    }
    return *this;
}

Ciorba::Ciorba(const Ciorba & other){
    pret = other.pret;
    denumire = other.denumire;
    ardei = other.ardei;
    smantana = other.smantana;
}

// Implementarea clasei Supa

std::istream & operator >> (std::istream & in, Supa & prod){
    std::cout << "Denumire: ";
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
    return in;
}

std::ostream & operator << (std::ostream & out, Supa & prod){
    out << "-- Supa --" << std::endl;
    out << "Denumire: " << prod.denumire << " --- " << prod.pret << " RON" << std::endl; 
    return out;
}

Supa & Supa::operator = (const Supa &other){
    if(this != &other){
        denumire = other.denumire;
        pret = other.pret;
    }
    return *this;
}

Supa::Supa(const Supa & other){
    denumire = other.denumire;
    pret = other.pret;
}

void Supa::printPreparat(){
    std::cout << "-- Supa --" << std::endl;
    std::cout << "Denumire: " << denumire << " --- " << pret << " RON" << std::endl; 
}

// Implementarea clasei Pui

std::istream & operator >> (std::istream & in, Pui & prod){
    std::cout << "Denumire: ";
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
    return in;
}

std::ostream & operator << (std::ostream & out, Pui & prod){
    out << "-- Pui --" << std::endl;
    out << "Denumire: " << prod.denumire << " --- " << prod.pret << " RON" << std::endl;
    return out; 
}

Pui & Pui::operator = (const Pui &other){
    if(this != &other){
        pret = other.pret;
        denumire = other.denumire;
    }
    return *this;
}

Pui::Pui(const Pui & other){
    pret = other.pret;
    denumire = other.denumire;
}

void Pui::printPreparat(){
    std::cout << "-- Pui --" << std::endl;
    std::cout << "Denumire: " << denumire << " --- " << pret << " RON" << std::endl;
}

// Implementarea clasei Vita

std::istream & operator >> (std::istream & in, Vita & prod){
    std::cout << "Denumire: ";
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
    return in;
}

std::ostream & operator << (std::ostream & out, Vita & prod){
    out << "-- Vita --" << std::endl;
    out << "Denumire: " << prod.denumire << " --- " << prod.pret << " RON" << std::endl;
    out << "Mentiuni: ";
    if(prod.modPreparare == 0){
        out << "In Sange" << std::endl;
    }else if(prod.modPreparare == 1){
        out << "Mediu" << std::endl;
    }else if(prod.modPreparare == 2){
        out << "Bine Facuta" << std::endl;
    }
    return out;    
}

void Vita::set_modPreparare(int ans){
    modPreparare = ans;
}

Vita & Vita::operator = (const Vita &other){
    if(this != &other){
        denumire = other.denumire;
        pret = other.pret;
        modPreparare = other.modPreparare;
    }
    return *this;
}

Vita::Vita(const Vita & other){
    denumire = other.denumire;
    pret = other.pret;
    modPreparare = other.modPreparare;
}

void Vita::printPreparat(){
    std::cout << "-- Vita --" << std::endl;
    std::cout << "Denumire: " << denumire << " --- " << pret << " RON" << std::endl;
    std::cout << "Mentiuni: ";
    if(modPreparare == 0){
        std::cout << "In Sange" << std::endl;
    }else if(modPreparare == 1){
        std::cout << "Mediu" << std::endl;
    }else if(modPreparare == 3){
        std::cout << "Bine Facuta" << std::endl;
    }
}

// Implementarea clasei Desert

Desert::Desert(const Desert & other){
    denumire = other.denumire;
    pret = other.pret;
}

// Implementarea clasei Inghetata

std::istream & operator >> (std::istream & in, Inghetata & prod){
    std::cout << "Denumire: ";
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
    return in;
}

std::ostream & operator << (std::ostream & out, Inghetata & prod){
    out << "-- Inghetata --" << std::endl;
    out << "Denumire: " << prod.denumire << " --- " << prod.pret << " RON" << std::endl;
    out << "Numar Cupe: " << prod.nrCupe << std::endl;
    return out;
}

void Inghetata::set_nrCupe(int ans){
    nrCupe = ans;
}

Inghetata & Inghetata::operator = (const Inghetata &other){
    if(this != &other){
        denumire = other.denumire;
        pret = other.pret;
        nrCupe = other.nrCupe;
    }
    return *this;
}

Inghetata::Inghetata(const Inghetata &other){
    denumire = other.denumire;
    pret = other.pret;
    nrCupe = other.nrCupe;
}

void Inghetata::printDesert(){
    std::cout << "-- Inghetata --" << std::endl;
    std::cout << "Denumire: " << denumire << " --- " << pret << " RON" << std::endl;
    std::cout << "Numar Cupe: " << nrCupe << std::endl;
}

// Implementare clasei Tort

std::istream & operator >> (std::istream &in, Tort &prod){
    std::cout << "Denumire:" << std::endl;
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
    return in;
}

std::ostream & operator << (std::ostream &out, Tort &prod){
    out << "-- Tort --" << std::endl;
    out << "Denumire: " << prod.denumire << " --- " << prod.pret << " RON" << std::endl;
    return out;
}

Tort & Tort::operator = (const Tort &other){
    if(this != &other){
        denumire = other.denumire;
        pret = other.pret;
    }
    return *this;
}

Tort::Tort(const Tort & other){
    denumire = other.denumire;
    pret = other.pret;
}

void Tort::printDesert(){
    std::cout << "-- Tort --" << std::endl;
    std::cout << "Denumire: " << denumire << " --- " << pret << " RON" << std::endl;
}

// Implementarea clasei Cartofi

std::istream & operator >> (std::istream &in, Cartofi &prod){
    std::cout << "Denumire: ";
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
    return in;
}

std::ostream & operator << (std::ostream &out, Cartofi &prod){
    out << "-- Cartofi --" << std::endl;
    out << "Denumire: " << prod.denumire << " --- " << prod.pret << " RON" << std::endl;
    return out;
}

Cartofi & Cartofi::operator = (const Cartofi &other){
    if(this != &other){
        denumire = other.denumire;
        pret = other.pret;
    }
    return *this;
}

Cartofi::Cartofi(const Cartofi & other){
    denumire = other.denumire;
    pret = other.pret;
}

void Cartofi::printPreparat(){
    std::cout << "-- Cartofi --" << std::endl;
    std::cout << "Denumire: " << denumire << " --- " << pret << " RON" << std::endl;
}

// Implementarea clasei Orez

std::istream & operator >> (std::istream &in, Orez &prod){
    std::cout << "Denumire: ";
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
    return in;
}

std::ostream & operator << (std::ostream &out, Orez &prod){
    out << "-- Orez --" << std::endl;
    out << "Denumire: " << prod.denumire << " --- " << prod.pret << " RON" << std::endl;
    return out;
}

Orez & Orez::operator = (const Orez &other){
    if(this != &other){
        denumire = other.denumire;
        pret = other.pret;
    }
    return *this;
}

Orez::Orez(const Orez & other){
    pret = other.pret;
    denumire = other.denumire;
}

void Orez::printPreparat(){
    std::cout << "-- Orez --" << std::endl;
    std::cout << "Denumire: " << denumire << " --- " << pret << " RON" << std::endl;
}