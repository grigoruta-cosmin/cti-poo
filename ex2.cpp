#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct Cerc{
    int raza;
};

struct Dreptunghi{
    int latime, lungime;
};

struct Patrat{
    int latura;
};

struct Triunghi{
    int cat1, cat2;
};

struct Cantitate{
    double grameGem;
    double grameFrisca;
};

void afiseazaTotal(Cantitate vector[], int count){
    if(count == 0){
        cout << "Nu s-a adaugat nicio prajitura!" << endl;
    }else{
        int grameTotalFrisca, grameTotalGem;
        grameTotalFrisca = grameTotalGem = 0;
        for(int i = 0; i < count; i++){
            grameTotalGem += vector[i].grameGem;
            grameTotalFrisca += vector[i].grameFrisca;
        }
        cout << "Necesarul de gem este : " << grameTotalGem << endl;
        cout << "Necesarul de frisca este : " << grameTotalFrisca << endl; 
    }
}

int main(){
    const double pi = 3.14;
    double volumTotal, suprafataTotala, grameGem, grameFrisca;
    int h, forma, indexVectorCantitate = 0;
    Cantitate vectorCantitate[50];
    volumTotal = suprafataTotala = grameGem = grameFrisca = 0;
    string comanda;
    Cerc cerc;
    Patrat patrat;
    Dreptunghi dreptunghi;
    Triunghi triunghi;
    while(comanda != "STOP"){
        cout << "Introduceti comanda:" << endl;
        cin >> comanda;
        if(comanda == "ADD"){
            cout << "Forma bazei" << endl;
            cout << "cerc - 1" << endl;
            cout << "dreptunghi - 2" << endl;
            cout << "patrat - 3" << endl;
            cout << "triunghi dreptunghic - 4" << endl;
            cin >> forma;
                switch (forma){
                    case 1:
                        cout << "Raza R:" << endl;
                        cin >> cerc.raza;
                        cout << endl;
                        cout << "Inaltime h:" << endl;
                        cin >> h;
                        volumTotal = pi * cerc.raza * cerc.raza * h;
                        suprafataTotala = 2 * pi * cerc.raza * h + pi * cerc.raza * cerc.raza;
                        vectorCantitate[indexVectorCantitate].grameGem = volumTotal * 2;
                        vectorCantitate[indexVectorCantitate].grameFrisca = suprafataTotala;
                        cout << "Necesarul de gem este : " << volumTotal * 2 << endl;
                        cout << "Necesarul de frisca este : " << suprafataTotala << endl; 
                        break;
                    case 2:
                        cout << "Lungime" << endl;
                        cin >> dreptunghi.lungime;
                        cout << endl;
                        cout << "Latime" << endl;
                        cin >> dreptunghi.latime;
                        cout << endl;
                        cout << "Inaltime h" << endl;
                        cin >> h;
                        volumTotal = dreptunghi.latime * dreptunghi.lungime * h;
                        suprafataTotala = 2 * (dreptunghi.lungime + dreptunghi.latime) * h + dreptunghi.latime * dreptunghi.lungime;
                        vectorCantitate[indexVectorCantitate].grameGem = volumTotal * 2;
                        vectorCantitate[indexVectorCantitate].grameFrisca = suprafataTotala;
                        cout << "Necesarul de gem este : " << volumTotal * 2 << endl;
                        cout << "Necesarul de frisca este : " << suprafataTotala << endl; 
                        break;
                    case 3:
                        cout << "Latura" << endl;
                        cin >> patrat.latura;
                        cout << endl;
                        cout << "Inaltime h:" << endl;
                        cin >> h;
                        volumTotal = patrat.latura * patrat.latura * h;
                        suprafataTotala = 4 * patrat.latura * h + patrat.latura * patrat.latura;
                        vectorCantitate[indexVectorCantitate].grameGem = volumTotal * 2;
                        vectorCantitate[indexVectorCantitate].grameFrisca = suprafataTotala;
                        cout << "Necesarul de gem este : " << volumTotal * 2 << endl;
                        cout << "Necesarul de frisca este : " << suprafataTotala << endl; 
                        break;
                    case 4:
                        cout << "Cateta 1:" << endl;
                        cin >> triunghi.cat1;
                        cout << endl;
                        cout << "Cateta 2:" << endl;
                        cin >> triunghi.cat2;
                        cout << endl;
                        cout << "Inaltime h:"<< endl;
                        cin >> h;
                        volumTotal = triunghi.cat1 * triunghi.cat2 * h;
                        suprafataTotala = h * (triunghi.cat1 + triunghi.cat2 + sqrt(triunghi.cat1 * triunghi.cat1 + triunghi.cat2 * triunghi.cat2)) + triunghi.cat1 * triunghi.cat2 / 2;
                        vectorCantitate[indexVectorCantitate].grameGem = volumTotal * 2;
                        vectorCantitate[indexVectorCantitate].grameFrisca = suprafataTotala;
                        cout << "Necesarul de gem este : " << volumTotal * 2 << endl;
                        cout << "Necesarul de frisca este : " << suprafataTotala << endl; 
                        break;
                    default:
                        cout << "Comanda Incorecta!" << endl;
                }
                indexVectorCantitate++;
        }else if(comanda == "TOTAL"){
            afiseazaTotal(vectorCantitate, indexVectorCantitate);
        }else if(comanda == "REMOVE"){
            int indexPrajitura;
            cout << "Prajitura ce se doreste a fi stearsa:" << endl;
            cin >> indexPrajitura;
            if(indexPrajitura - 1 > indexVectorCantitate){
                cout << "Prajitura " << indexPrajitura << " nu a fost inca adaugata!" << endl;
            }else{
                indexPrajitura--; // deincrementam intrucat vectorul este indexat de la 0
                vectorCantitate[indexPrajitura].grameFrisca = vectorCantitate[indexPrajitura].grameGem = 0;
                indexVectorCantitate--;
                cout << "Prajitura " << indexPrajitura + 1 << " a fost eliminata" << endl;
            }
        }
    }
    return 0;
}