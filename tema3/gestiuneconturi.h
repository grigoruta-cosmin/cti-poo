#ifndef GESTIUNE_CONTURI_H
#define GESTIUNE_CONTURI_H
#include <bits/stdc++.h>
#include "cont.h"

template<class T>
class GestiuneConturi{
    std::unordered_map<int, std::vector<Operatiune>> istoricConturi;
    std::vector<T*> conturi;
public:
    GestiuneConturi() = default;
    GestiuneConturi(const GestiuneConturi<T> &);
    void adaugaCont();
    void adaugaCont(const T &);
    GestiuneConturi<T> & operator=(const GestiuneConturi<T>&);
    void efectueazaTranzactieLaContul(int);
    void afiseazaConturi();
    ~GestiuneConturi() = default;
};

template<class T>
GestiuneConturi<T>::GestiuneConturi(const GestiuneConturi<T> &other){
    istoricConturi = other.istoricConturi;
    conturi = other.conturi;
}

template<class T>
GestiuneConturi<T> & GestiuneConturi<T>::operator=(const GestiuneConturi<T> &other){
    if(this != &other){
        istoricConturi = other.istoricConturi;
        conturi = other.conturi;
    }
    return *this;
}

template<class T>
void GestiuneConturi<T>::adaugaCont(){
    T *aux = new T;
    std::cin >> *aux;
    conturi.push_back(aux);
    istoricConturi.insert(std::make_pair(aux->getIdCont(), aux->getIstoric()));
}

template<class T>
void GestiuneConturi<T>::adaugaCont(const T &other){
    std::cout << "adauga cont: "<< other.getIdCont() << std::endl;
    conturi.push_back(new T(other));
    istoricConturi.insert(std::make_pair(other.getIdCont(), other.getIstoric()));
}

template<class T>
void GestiuneConturi<T>::efectueazaTranzactieLaContul(int index){
    int op;
    double sumaAux;
    if(conturi.size() - 1 < index){
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
                break;
            default:
                std::cout << "Comanda incorecta!" << std::endl;
                break;
            }
        }else if(dynamic_cast<ContEconomii *>(conturi[index])){
            std::cout << "Se pot efectua urmatoarele tranzactii:" << std::endl;
            std::cout << "1. Depunere" << std::endl;
            std::cout << "2. Retragere" << std::endl;
            std::cin >> op;
            dynamic_cast<ContEconomii *>(conturi[index])->tranzactie(op);
        }
    }
    if(istoricConturi.find(conturi[index]->getIdCont()) == istoricConturi.end()){
        std::cout << "ajung aici" << std::endl;
    }else{
        std::cout << "ajung iaic si e ok" << std::endl;
        istoricConturi.find(conturi[index]->getIdCont())->second = conturi[index]->getIstoric();
    }   
}

template<class T>
void GestiuneConturi<T>::afiseazaConturi(){
    for(auto it = istoricConturi.begin(); it != istoricConturi.end(); it++){
        std::cout << it->first << std::endl;
        for(int i = 0; i < it->second.size(); i++){
            std::cout << it->second[i];
        }
    }
}
#endif