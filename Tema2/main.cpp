#include <bits/stdc++.h>
#include "bautura.h"
#include "comanda.h"
#include "meniu.h"
#include "masa.h"
#include "restaurant.h"
#include "managementRestaurant.h"
#include <unistd.h>

ManagementRestaurant * ManagementRestaurant::Instance = nullptr;
Meniu Restaurant::meniuRestaurant;

int main(){
    ManagementRestaurant * management;
    Restaurant restaurant;
    bool flag = true;
    int op, nrClienti, indexMasa;
    while(flag){
        std::cout << "1. Citeste Restaurant" << std::endl;
        std::cout << "2. Afiseaza Mese Ocupate" << std::endl;
        std::cout << "3. Intra Clienti" << std::endl;
        std::cout << "4. Obtine Comanda" << std::endl;
        std::cout << "5. Client vrea nota separat" << std::endl;
        std::cout << "6. Nota la toata masa" << std::endl;
        std::cout << "7. Citim n restaurante" << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cin >> op;
        switch (op){
        case 1:
            std::cout << "Se citeste Restaurantul" << std::endl;
            std::cin >> restaurant;
            break;
        case 2:
            restaurant.afisMeseOcupate();
            break;
        case 3:
            std::cout << "Se citeste numarul de clienti" << std::endl;
            std::cin >> nrClienti;
            restaurant.intraClienti(nrClienti);
            break;
        case 4:
            std::cout << "Introduceti indexul mesei unde doriti sa se ia comanda" << std::endl;
            std::cin >> indexMasa;
            restaurant.obtineComanda(indexMasa);
            break;
        case 5:
            std::cout << "Introduceti indexul mesei de unde doreste clientul sa plece " << std::endl;
            std::cin >> indexMasa;
            restaurant.clientPleaca(indexMasa);
            break;
        case 6:
            std::cout << "Inroduceti indexul mesei care doreste nota integrala" << std::endl;
            std::cin >> indexMasa;
            restaurant.notaToataMasa(indexMasa);
            break;
        case 7:
            std::cin >> *management;
            std::cout << *management;
            break;
        case 8:
            flag = 0;
            break;
        default:
            std::cout << "Optiune incorecta, se va opri citirea!" << std::endl;
            break;
        }
    }
}