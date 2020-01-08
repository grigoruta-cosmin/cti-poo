#include <bits/stdc++.h>
#include "cont.h"

void Cont::afisareIstoric() const {
    for(int i = istoric.size() - 1; i >= 0; i--)
        std::cout << istoric[i];
}

std::ostream & Cont::print(std::ostream &os) const {
    os << "ID CONT: " << idCont << std::endl;
    os << "NUME: " << numeDetinator << std::endl;
    os << "SOLD: " << sold << std::endl;
    os << "DATA: " << data << std::endl;
    return os;
}

std::ostream & operator<<(std::ostream &os, const Cont &other){
    return other.print(os);
}

std::istream & Cont::read(std::istream &os){
    std::cout << "NUME:" << std::endl;
    os >> numeDetinator;
    std::cout << "SOLD:" << std::endl;
    os >> sold;
    std::cout << "DATA: " << std::endl;
    os >> data;
    return os;
}

std::istream & operator>>(std::istream &os, Cont &other){
    return other.read(os);
}

Cont & Cont::operator=(const Cont &other){
    if(this != &other){
        idCont = other.idCont;
        numeDetinator = other.numeDetinator;
        sold = other.sold;
    }
    return *this;
}

Cont::Cont(const Cont &other){
    numarCont++; idCont = numarCont;
    idCont = other.idCont;
    numeDetinator = other.numeDetinator;
    sold = other.sold;
}

void Cont::retragere(double suma){
    sold -= suma;
    istoric.push_back(Operatiune("RETRAGERE", sold));
}

void Cont::depunere(double suma){
    sold += suma;
    istoric.push_back(Operatiune("DEPUNERE", sold));
}

std::ostream & ContCurent::print(std::ostream &os) const {
    os << "ID CONT: " << idCont << std::endl;
    os << "NUME: " << numeDetinator << std::endl;
    os << "SOLD: " << sold << std::endl;
    os << "DATA: " << data << std::endl;
    os << "NUMAR TRANZACTII GRATUITE: " << numarTranzactiiGratuite << std::endl;
    os << "TAXA TRANZACTIE PERCEPUTA LA EXTRAGEREA DE LA ALT BANCOMAT: " << taxaTranzactieAltBancomat << std::endl;
    os << "TAXA TRANZACTIE PERCEPUTA LA CUMPARATURI ONLINE: " << taxaTranzactieOnline << std::endl;
    return os;
}

std::istream & ContCurent::read(std::istream &os){
    std::cout << "NUME:" << std::endl;
    os >> numeDetinator;
    std::cout << "SOLD:" << std::endl;
    os >> sold;
    std::cout << "DATA:" << std::endl;
    os >> data;
    std::cout << "NUMAR TRANZACTII GRATUITE:" << std::endl;
    os >> numarTranzactiiGratuite;
    std::cout << "TAXA TRANZACTIE PERCEPUTA LA EXTRAGEREA DE LA ALT BANCOMAT:" << std::endl;
    os >> taxaTranzactieAltBancomat;
    std::cout << "TAXA TRANZACTIE PERCEPUTA LA CUMPARATURI ONLINE:" << std::endl;
    os >> taxaTranzactieOnline;
    return os; 
}

ContCurent::ContCurent(const ContCurent &other) : Cont(other){
    numarTranzactiiGratuite = other.numarTranzactiiGratuite;
    taxaTranzactieAltBancomat = other.taxaTranzactieAltBancomat;
    taxaTranzactieOnline = other.taxaTranzactieOnline;
}

ContCurent & ContCurent::operator=(const ContCurent &other){
    if(this != &other){
        idCont = other.idCont;
        sold = other.idCont;
        numeDetinator = other.numeDetinator;
        numarTranzactiiGratuite = other.numarTranzactiiGratuite;
        taxaTranzactieAltBancomat = other.taxaTranzactieAltBancomat;
        taxaTranzactieOnline = other.taxaTranzactieOnline;
    }
    return *this;
}

void ContCurent::depunereContCurent(double suma){
    Cont::depunere(suma);
}

void ContCurent::retragereContCurent(double suma){
    if(sold - suma >= 0){
        Cont::retragere(suma);
    }else{
        std::cout << "****SOLD INDISPONIBIL****" << std::endl;
    }
}

void ContCurent::plataOnline(double suma){
    if(numarTranzactiiGratuite > 0){
        if(sold - suma >= 0){
            Cont::retragere(suma);
            numarTranzactiiGratuite--;
        }else{
            std::cout << "****SOLD INSUFICIENT****" << std::endl;
        }
    }else{
        if(sold - suma - taxaTranzactieOnline >= 0){
            std::cout << "Atentie numarul de tranzactii gratuite a fost depasit. Se va percepe un comision in functie de contract!" << std::endl;
            Cont::retragere(suma + taxaTranzactieOnline);
        }else{
            std::cout << "****SOLD INSUFICIENT****" << std::endl;
        }
    }
}

void ContCurent::retragereAltBancomat(double suma){
    if(numarTranzactiiGratuite > 0){
        if(sold - suma >= 0){
            Cont::retragere(suma);
            numarTranzactiiGratuite--;
        }else{
            std::cout << "****SOLD INSUFICIENT****" << std::endl;
        }
    }else{
        if(sold - suma - taxaTranzactieAltBancomat >= 0){
            std::cout << "Atentie numarul de tranzactii gratuite a fost depasit. Se va percepe o taxa suplimentara in functie de contract!" << std::endl;
            Cont::retragere(suma + taxaTranzactieAltBancomat);
        }else{
            std::cout << "****SOLD INSUFICIENT****" << std::endl;
        }
    }
}

ContEconomii::ContEconomii(const ContEconomii &other) : Cont(other){
    tipulDobanzii = other.tipulDobanzii;
    dobanda = other.dobanda;
    dataScadenta = other.dataScadenta;
}

ContEconomii & ContEconomii::operator=(const ContEconomii &other){
    if(this != &other){
        idCont = other.idCont;
        numeDetinator = other.numeDetinator;
        sold = other.sold;
        tipulDobanzii = other.tipulDobanzii;
        dobanda = other.dobanda;
        dataScadenta = other.dataScadenta;
    }
}

void ContEconomii::adaugaDobanda(){
    sold += dobanda*sold;
}

std::ostream & ContEconomii::print(std::ostream &os) const{
    os << "ID CONT: " << idCont << std::endl;
    os << "NUME: " << numeDetinator << std::endl;
    os << "SOLD: " << sold << std::endl;
    os << "DATA: " << data << std::endl;
    os << "DATA SCADENTA: " << dataScadenta << std::endl;
    os << "TIP DOBANDA: ";
    if(tipulDobanzii == 1){
        os << "3 LUNI" << std::endl;
    }else if(tipulDobanzii == 2){
        os << "6 LUNI" << std::endl;
    }else if(tipulDobanzii == 3){
        os << "1 AN" << std::endl;
    }
    os << "DOBANDA: " << dobanda << std::endl; 
    return os;
}

std::istream & ContEconomii::read(std::istream &os){
    std::cout << "NUME:" << std::endl;
    os >> numeDetinator;
    std::cout << "SOLD:" << std::endl;
    os >> sold;
    std::cout << "DATA:" << std::endl;
    os >> data;
    std::cout << "DATA SCADENTA:" << std::endl;
    os >> dataScadenta;
    std::cout << "TIP DOBANDA (1 - 3 LUNI, 2 - 6 LUNI, 3 - 1 AN):" << std::endl;
    os >> tipulDobanzii;
    std::cout << "DOBANDA (0,1):" << std::endl;
    os >> dobanda;
    return os;    
}

void ContEconomii::depunere(double suma){
    Cont::depunere(suma);
}

void ContEconomii::retragere(double suma){
    if(sold - suma >= 0){
        Cont::retragere(suma);
    }else{
        std::cout << "****SOLD INSUFICIENT****" << std::endl;
    }
}

void ContEconomii::tranzactie(int tip){
    double suma;
    Data auxData, diffData;
    std::cin >> auxData;    
    if(tip == 1){
        std::cout << "Introduceti suma:" << std::endl;
        std::cin >> suma;
        this->depunere(suma);
    }else if(tip == 2){
        if(dataScadenta < auxData){
            std::cout << "Introduceti suma:" << std::endl;
            std::cin >> suma;
            this->retragere(suma);
        }else{
            std::cout << "CONFORM CONTRACTULUI NU SUNT PERMISE EXTRAGERI" << std::endl;
            std::cout << "DIN CONTUL DE ECONOMII INAINTE DE DATA SCADENTA!" << std::endl;
        }
    }
    if(tipulDobanzii == 3 && diffData.getThird() > 0){
        adaugaDobanda();
        ultimaDataActualizare = auxData;
    }else if(tipulDobanzii == 2 && diffData.getSecond() > 0){
        if(diffData.getThird() == 0){
            sold += diffData.getSecond() / 6 * sold * dobanda;
        }else if(diffData.getThird() > 0){
            sold += (diffData.getSecond() + diffData.getThird() * 12) / 6 * sold * dobanda;
        }
        ultimaDataActualizare = auxData;
    }else if(tipulDobanzii == 1 && diffData.getSecond() > 0){
        if(diffData.getThird() == 0){
            sold += diffData.getSecond() / 3 * sold * dobanda;
        }else if(diffData.getThird() > 0){
            sold += (diffData.getSecond() + diffData.getThird() * 12) / 3 * sold * dobanda;
        }
        ultimaDataActualizare = auxData;        
    }
}
