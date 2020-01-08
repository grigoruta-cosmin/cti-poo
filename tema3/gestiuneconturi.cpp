#include "gestiuneconturi.h"

template<class T>
void GestiuneConturi<T>::adaugaCont(){
    T aux;
    std::cin >> aux;
    conturi.push_back(aux);
}

template<class T>
void GestiuneConturi<T>::efectueazaTranzactieLaContul(int index){
    int op;
    double sumaAux;
    if(conturi.size() - 1 <= index){
        std::cout << "Nu exista acest cont!" << std::endl;
    }else{
        if(dynamic_cast<ContCurent *>(conturi[index])){
            std::cout << "Se pot efectua urmatoarele tranzactii:" << std::endl;
            std::cout << "1. Depunere" << std::endl;
            std::cout << "2. Retragere" << std::endl;
            std::cout << "3. Plata Online" << std::endl;
            std::cout << "4. Retragere de la un alt ATM" << std::endl; 
            std::cin >> op;
            std::cout << "Introduceti suma:" << std::endl;
            std::cin >> sumaAux;
            switch (op){
            case 1:
                dynamic_cast<ContCurent *>(conturi[index])->depunereContCurent(sumaAux);
                break;
            case 2:
                dynamic_cast<ContCurent *>(conturi[index])->retragereContCurent(sumaAux);
                break;
            case 3:
                dynamic_cast<ContCurent *>(conturi[index])->plataOnline(sumaAux);
                break;
            case 4:
                dynamic_cast<ContCurent *>(conturi[index])->retragereAltBancomat(sumaAux);
            default:
                std::cout << "Comanda incorecta!" << std::endl;
                break;
            }
        }else if(dynamic_cast<ContEconomii *>(conturi[index])){
            std::cout << "Se pot efectua urmatoarele tranzactii:" << std::endl;
            std::cout << "1. Depunere" << std::endl;
            std::cout << "2. Retragere" << std::endl;
            std::cin >> op;
            dynamic_cast<ContEconomii *>->tranzactie(op);
        }
    }
}