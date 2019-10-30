#include <bits/stdc++.h>
#include "graf_ponderat.h"
#include "list.h"
#include "muchie_pon.h"
#include "vectorGraf.h"

int main(){
    vectorGraf vector;
    Graf_ponderat graf, graf1, graf2;
    int flag = 1, optiune, nod, nod_i, nod_f;
    while(flag){
        std::cout << "1. Constructorul de initializare" << std::endl;
        std::cout << "2. Constructorul de copiere" << std::endl;
        std::cout << "3. Afisarea grafului" << std::endl;
        std::cout << "4. Parcurgerea in latime" << std::endl;
        std::cout << "5. Parcurgerea in adancime" << std::endl;
        std::cout << "6. Determinarea matricii ponderilor de drum minim" << std::endl;
        std::cout << "7. Verificare daca graful este conex" << std::endl;
        std::cout << "8. Determinarea nodurilor intermediare de pe un drum de pondere minima" << std::endl;
        std::cout << "9. Inmultirea a doua grafuri" << std::endl;
        std::cout << "10. Creaza un vector de grafuri ponderate" << std::endl;
        std::cout << "11. Exit" << std::endl;
        std::cin >> optiune;
        switch (optiune){
            case 1:{
                int numar;
                std::cout << "Se va citi un numar de noduri" << std::endl;
                std::cout << "care va initializa graful cu valori nule" << std::endl;
                std::cin >> numar;
                Graf_ponderat graf(numar);
                std::cout << graf;
            }
            break;
            case 2:{
                std::cout << "Vom citi un graf, ulterior initializam un alt obiect prin acel graf" << std::endl;
                std::cout << "O sa observam ca cel de-al doilea graf a preluat toate datele primului" << std::endl;
                Graf_ponderat graf1;
                std::cin >> graf1;
                Graf_ponderat graf2(graf1);
                std::cout << graf2;
            }
            break;
            case 3:
                std::cout << "Citirea se realizeaza prin supraincarcarea operatorului >> " << std::endl;
                std::cin >> graf;
                std::cout << "Afisarea se realizeaza prin supraincarcarea operatorului << " << std::endl;
                std::cout << graf;
            break;
            case 4:
                std::cout << "Se va citi nodul de unde se doreste inceputa parcurgerea " << std::endl;
                std::cin >> nod;
                graf.BFS(nod);
            break;
            case 5:
                std::cout << "Se va citi nodul de unde se doreste inceputa parcurgerea " << std::endl;
                std::cin >> nod;
                graf.DFS(nod);
            break;
            case 6:
                graf.calculeazaMatricePonderiMinime();
                graf.afisareMatrice();
            break;
            case 7:
                if(graf.verificareConex()){
                    std::cout << "Graful est conex" << std::endl;
                }else{
                    std::cout << "Graful nu este conex" << std::endl;
                }
            break;
            case 8:
                std::cout << "Nod initial:" << std::endl;
                std::cin >> nod_i;
                std::cout << "Nod final" << std::endl;
                std::cin >> nod_f;
                graf.scriuDrum(nod_i, nod_f);
            break;
            case 9:
                std::cout << "Se va citi alt graf pentru a putea efectua operatia de inmultire" << std::endl;
                std::cin >> graf1;
                graf2 = graf * graf1;
                std::cout << graf2;
            break;
            case 10:
                std::cout << "Se va citi un numarul de grafuri ce doresc a fi stocate" << std::endl;
                std::cin >> vector;
                std::cout << vector;
            break;
            case 11:
                flag = 0;
            break;
            default:
                std::cout << "Comanda incorecta" << std::endl;
            break;
        }
    }
    return 0;
}