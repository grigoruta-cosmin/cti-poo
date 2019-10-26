#include "graf_ponderat.h"
#include "list.h"
#include "muchie_pon.h"
#include <climits>

Graf_ponderat::Graf_ponderat(){
    nrMuchii = nrNoduri = 0;
    vizitat = nullptr;
    matriceAdiacenta = matricePonderi = matricePonderiMinime = nullptr;
    listeAdiacenta = nullptr;
}

Graf_ponderat::Graf_ponderat(int nrNoduri){
    this->nrNoduri = nrNoduri;
    matriceAdiacenta = new int*[nrNoduri + 1];
    matricePonderi = new int*[nrNoduri + 1];
    matricePonderiMinime = new int*[nrNoduri + 1];
    listeAdiacenta = new List[nrNoduri + 1];
    vizitat = new int[nrNoduri + 1];
    for(int i = 1; i <= nrNoduri; i++){
        matriceAdiacenta[i] = new int[nrNoduri + 1];
        matricePonderi[i] = new int[nrNoduri + 1];
        matricePonderiMinime[i] = new int[nrNoduri + 1];
        listeAdiacenta[i].push(i);
        vizitat[i] = 0;
    }
    for(int i = 1; i <= nrNoduri; i++)
        for(int j = 1; j <= nrNoduri; j++){
            if(i == j){
                matricePonderi[i][j] = matricePonderiMinime[i][j] = 0;
            }else{
                matricePonderi[i][j] = matricePonderiMinime[i][j] = inf;
            }
            matriceAdiacenta[i][j] = 0;
        }
}

Graf_ponderat::Graf_ponderat(const Graf_ponderat& graf){
    nrNoduri = graf.nrNoduri;
    matriceAdiacenta = new int*[nrNoduri + 1];
    matricePonderi = new int*[nrNoduri + 1];
    matricePonderiMinime = new int*[nrNoduri + 1];
    listeAdiacenta = new List[nrNoduri + 1];
    vizitat = new int[nrNoduri + 1];
    for(int i = 1; i <= nrNoduri; i++){
        matriceAdiacenta[i] = new int[nrNoduri + 1];
        matricePonderi[i] = new int[nrNoduri + 1];
        matricePonderiMinime[i] = new int[nrNoduri + 1];
        listeAdiacenta[i].push(i);
        vizitat[i] = 0;        
    }
    for(int i = 1; i <= nrNoduri; i++){
        for(int j = 1; j <= nrNoduri; j++){
            matriceAdiacenta[i][j] = graf.matriceAdiacenta[i][j];
            matricePonderi[i][j] = graf.matricePonderi[i][j];
            if(matriceAdiacenta[i][j] == 1){
                listeAdiacenta[i].push(j);
            }
        }
    }
    for(auto it = graf.muchii.begin(); it != graf.muchii.end(); it++)
        muchii.push_back((*it));
}

int Graf_ponderat::get_nrNoduri(){
    return nrNoduri;
}

int Graf_ponderat::get_nrMuchii(){
    return nrMuchii;
}

void Graf_ponderat::afisareMatrice(){
    std::cout << "Matricea adiacenta:\n";
    for(int i = 1; i <= nrNoduri; i++){
        for(int j = 1; j <= nrNoduri; j++)
            std::cout << matriceAdiacenta[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "Matricea ponderilor:\n";
    for(int i = 1; i <= nrNoduri; i++){
        for(int j = 1; j <= nrNoduri; j++)
            if(matricePonderi[i][j] == 1000){
                std::cout << "inf" << " ";
            }else{
                std::cout << matricePonderi[i][j] << " ";
            }
        std::cout << std::endl;
    }
    std::cout << "Matricea ponderilor minime:\n";
    for(int i = 1; i <= nrNoduri; i++){
        for(int j = 1; j <= nrNoduri; j++)
            std::cout << matricePonderiMinime[i][j] << " ";
        std::cout << std::endl;
    }
}

void Graf_ponderat::calculeazaMatricePonderiMinime(){
    for(int i = 1; i <= nrNoduri; i++){
        for(int j = 1; j <= nrNoduri; j++){
            matricePonderiMinime[i][j] = matricePonderi[i][j];
        }
    }
    for(int k = 1; k <= nrNoduri; k++){
        for(int i = 1; i <= nrNoduri; i++){
            for(int j = 1; j <= nrNoduri; j++){
                if(matricePonderiMinime[i][j] > matricePonderiMinime[i][k] + matricePonderiMinime[k][j])
                    matricePonderiMinime[i][j] = matricePonderiMinime[i][k] + matricePonderiMinime[k][j];
            }
        }
    }
}

Graf_ponderat::~Graf_ponderat(){
    for(int i = 1; i <= nrNoduri; i++){
        delete[] matricePonderi[i];
        delete[] matriceAdiacenta[i];
        delete[] matricePonderiMinime[i];
        listeAdiacenta[i].deleteList();
    }
    delete[] matriceAdiacenta;
    delete[] matricePonderi;
    delete[] listeAdiacenta;
    delete[] matriceAdiacenta;
    delete[] matricePonderi;
    delete[] matricePonderiMinime;
}

std::ostream & operator <<(std::ostream &out, const Graf_ponderat &graf){
    int mod;
    std::cout << "--Selecteaza modul de afisare--" << std::endl;
    std::cout << "1. Matrice de adiacenta" << std::endl;
    std::cout << "2. Liste de adiacenta" << std::endl;
    std::cout << "3. Liste de muchii" << std::endl;
    std::cin >> mod;
    switch(mod){
        case 1:
            for(int i = 1; i <= graf.nrNoduri; i++){
                for(int j = 1; j <= graf.nrNoduri; j++){
                    out << graf.matriceAdiacenta[i][j] << " ";
                }
                out << std::endl;
            }
        break;
        case 2:
            for(int i = 1; i <= graf.nrNoduri; i++)
                graf.listeAdiacenta[i].printList();
        break;
        case 3:
            for(auto it = graf.muchii.begin(); it != graf.muchii.end(); it++)
                (*it).afis();
        break;
        default:
            std::cout << "Comanda incorecta";
    }
    return out;
}

std::istream & operator >> (std::istream &in, Graf_ponderat &graf){
    std::string numeFisier;
    MuchiePon aux;
    std::cout << "Introduceti nume fisier:" << std::endl;
    std::cin >> numeFisier;
    int pondere, x, y;
    std::ifstream fisier(numeFisier);
    fisier >> graf.nrNoduri >> graf.nrMuchii;
    graf.matriceAdiacenta = new int*[graf.nrNoduri + 1];
    graf.matricePonderi = new int*[graf.nrNoduri + 1];
    graf.matricePonderiMinime = new int*[graf.nrNoduri + 1];
    graf.listeAdiacenta = new List[graf.nrNoduri + 1];
    graf.vizitat = new int[graf.nrNoduri + 1];
    for(int i = 1; i <= graf.nrNoduri; i++){
        graf.matriceAdiacenta[i] = new int[graf.nrNoduri + 1];
        graf.matricePonderi[i] = new int[graf.nrNoduri + 1];
        graf.matricePonderiMinime[i] = new int[graf.nrNoduri + 1];
        graf.listeAdiacenta[i].push(i);
        graf.vizitat[i] = 0;
    }
    for(int i = 1; i <= graf.nrNoduri; i++)
        for(int j = 1; j <= graf.nrNoduri; j++){
            if(i == j){
                graf.matricePonderi[i][j] = graf.matricePonderiMinime[i][j] = 0;
            }else{
                graf.matricePonderi[i][j] = graf.matricePonderiMinime[i][j] = graf.inf;
            }
            graf.matriceAdiacenta[i][j] = 0;
        }
    while(!fisier.eof()){
        fisier >> x >> y >> pondere;
        MuchiePon aux(x,y,pondere);
        graf.muchii.push_back(aux);
        graf.listeAdiacenta[x].push(y);
        graf.listeAdiacenta[y].push(x);
        graf.matriceAdiacenta[x][y] = graf.matriceAdiacenta[y][x] = 1;
        graf.matricePonderi[x][y] = graf.matricePonderi[y][x] = graf.matricePonderiMinime[x][y] = graf.matricePonderiMinime[y][x] = pondere;
    }
    return in;
}

void Graf_ponderat::BFS(int nod){
    int prim, ultim;
    int *coada, *vizitati;
    coada = new int[nrNoduri + 1];
    vizitati = new int[nrNoduri + 1];
    for(int i = 1; i <= nrNoduri; i++)
        coada[i] = vizitati[i] = 0;
    prim = ultim = 1;
    coada[ultim] = nod;
    //std::cout << "ajung aici" << std::endl;
    while(prim <= ultim){
        for(int i = 1; i <= nrNoduri; i++){
            if(matriceAdiacenta[coada[prim]][i] == 1)
                if(vizitati[i] == 0){
                    ultim++;
                    coada[ultim] = i;
                    std::cout << i << " ";
                    vizitati[i] = 1;
                }
        }
        prim++;
    }
    std::cout << std::endl;
}

void Graf_ponderat::DFS(int nod){
    std::cout << nod << " ";
    vizitat[nod] = 1;
    for(int i = 1; i <= nrNoduri; i++)
        if(matriceAdiacenta[nod][i] == 1 && vizitat[i] == 0)
            DFS(i);
}

bool Graf_ponderat::verificareConex(){
    for(int i = 1; i <= nrNoduri; i++)
        if(vizitat[i] == 0)
            return false;
    return true;
}

Graf_ponderat operator *(Graf_ponderat &g1, Graf_ponderat &g2){
    if(g1.nrNoduri == g2.nrNoduri){
        int aux = g1.nrNoduri;
        Graf_ponderat res(aux);
        for(auto ig1 = g1.muchii.begin(); ig1 != g1.muchii.end(); ig1++){
            for(auto ig2 = g2.muchii.begin(); ig2 != g2.muchii.end(); ig2++){
                if((*ig1).get_a() == (*ig2).get_a() && (*ig1).get_b() == (*ig2).get_b() && ig1 != ig2){
                    res.matriceAdiacenta[(*ig1).get_a()][(*ig1).get_b()] = res.matriceAdiacenta[(*ig1).get_b()][(*ig2).get_a()] = 1;
                    if((*ig1).get_pondere() > (*ig2).get_pondere()){
                        res.muchii.push_back(*ig2);
                    }else{
                        res.muchii.push_back(*ig1);
                    }
                }
            }
        }
        for(auto it = res.muchii.begin(); it != res.muchii.end(); it++){
            res.matricePonderi[(*it).get_a()][(*it).get_b()] = res.matricePonderi[(*it).get_b()][(*it).get_a()] = (*it).get_pondere();
            res.matricePonderiMinime[(*it).get_a()][(*it).get_b()] = res.matricePonderiMinime[(*it).get_b()][(*it).get_a()] = (*it).get_pondere();
            res.listeAdiacenta[(*it).get_a()].push((*it).get_b());
            res.listeAdiacenta[(*it).get_b()].push((*it).get_a());
        }
        res.calculeazaMatricePonderiMinime();
        return res;
    }else{
        Graf_ponderat res(3);
        std::cout << "Operatia nu poate fi efectuata!" << std::endl;
        return res;
    }
}

Graf_ponderat & Graf_ponderat::operator =(const Graf_ponderat& graf){
    if(this != &graf){
        for(int i = 1; i <= nrNoduri; i++){
            delete[] matricePonderi[i];
            delete[] matriceAdiacenta[i];
            delete[] matricePonderiMinime[i];
            listeAdiacenta[i].deleteList();
        }
        delete[] listeAdiacenta;
        delete[] matriceAdiacenta;
        delete[] matricePonderi;
        delete[] matricePonderiMinime;
        nrNoduri = graf.nrNoduri;
        matriceAdiacenta = new int*[nrNoduri + 1];
        matricePonderi = new int*[nrNoduri + 1];
        matricePonderiMinime = new int*[nrNoduri + 1];
        listeAdiacenta = new List[nrNoduri + 1];
        vizitat = new int[nrNoduri + 1];
        for(int i = 1; i <= nrNoduri; i++){
            matriceAdiacenta[i] = new int[nrNoduri + 1];
            matricePonderi[i] = new int[nrNoduri + 1];
            matricePonderiMinime[i] = new int[nrNoduri + 1];
            listeAdiacenta[i].push(i);
            vizitat[i] = 0;        
        }
        for(int i = 1; i <= nrNoduri; i++){
            for(int j = 1; j <= nrNoduri; j++){
                matriceAdiacenta[i][j] = graf.matriceAdiacenta[i][j];
                matricePonderi[i][j] = graf.matricePonderi[i][j];
                matricePonderiMinime[i][j] = graf.matricePonderiMinime[i][j];
                if(matriceAdiacenta[i][j] == 1){
                    listeAdiacenta[i].push(j);
                }
            }
        }
        for(auto it = graf.muchii.begin(); it != graf.muchii.end(); it++)
            muchii.push_back((*it)); 
    }
    return *this;
}

void Graf_ponderat::descompunDrum(int i, int j){
    int ok = 0;
    int k = 1;
    while(k <= nrNoduri && !ok){
        if(i != k && j != k)
            if(matricePonderiMinime[i][j] == matricePonderiMinime[i][k] + matricePonderiMinime[k][j]){
                descompunDrum(i,k);
                descompunDrum(k,j);
                ok = 1;
            }
        k++;
    }
    if(!ok)
        std::cout << j << " ";
}

void Graf_ponderat::scriuDrum(int nod_i, int nod_f){
    descompunDrum(nod_i, nod_f);
}
