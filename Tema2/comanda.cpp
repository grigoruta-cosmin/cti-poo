#include "comanda.h"

Comanda::Comanda() : countComandaBautura(0), countComandaMancare(0), countComandaDesert(0){}

Comanda::Comanda(int countComandaMancare = 0, int countComandaBautura = 0, int countComandaDesert = 0, double notaDePlata = 0) :
    countComandaBautura(countComandaBautura), countComandaMancare(countComandaMancare), notaDePlata(notaDePlata){
    for(int i = 0; i < countComandaMancare; i++)
        comandaMancare.push_back(new Mancare());
    for(int i = 0; i < countComandaBautura; i++)
        comandaBautura.push_back(new Bautura());
    for(int i = 0; i < countComandaDesert; i++)
        comandaDesert.push_back(new Desert());
}

Comanda::Comanda(const Comanda &other){
        for(auto &i : comandaMancare)
            delete i;
        comandaMancare.clear();
        
        for(auto &i : comandaDesert)
            delete i;
        comandaDesert.clear();
        
        for(auto &i : comandaBautura)
            delete i;
        comandaBautura.clear();
    comandaBautura = other.comandaBautura;
    comandaDesert = other.comandaDesert;
    comandaMancare = other.comandaMancare;
    countComandaBautura = other.countComandaBautura;
    countComandaDesert = other.countComandaDesert;
    countComandaMancare = other.countComandaMancare;
    notaDePlata = other.notaDePlata;
    meniu = other.meniu;   
}

void Comanda::setComanda(){
    notaDePlata = 0;
    countComandaBautura = 0;
    countComandaDesert = 0;
    countComandaMancare = 0;
    bool flagGarnitura = false;
    int op, opBautura, opMancare, opDesert, opCantVinPahar, opArdei, opSmantana, opCupe, opVita;
    Bautura *auxiliar_b;
    Mancare *auxiliar_m;
    Desert *auxiliar_d;
    int flag = 1;
    std::cout << "De Baut va aduc ceva?" << std::endl;
    std::cout << "1.Da" << std::endl;
    std::cout << "2.Nu" << std::endl;
    std::cout << "Optiune: " << std::endl;
    std::cin >> op;
    switch (op)
    {
    case 1:
        while(flag){
            for(int i = 0; i < meniu.listaBautura.size(); i++)
                std::cout << i + 1 << ". " << meniu.listaBautura[i]->get_denumire() << std::endl;
            std::cout << meniu.listaBautura.size() + 1 << ". Gata!" << std::endl;
            std::cout << "Se va citi optiunea: " << std::endl;
            std::cin >> opBautura;
            if(opBautura == meniu.listaBautura.size() + 1){
                flag = 0;
            }else if(opBautura < 1 || opBautura > meniu.countListaBautura + 1){
                std::cout << "Optiune incorecta. Se opreste citirea!" << std::endl;
                flag = 0;
            }else{
                VinPahar *vinPahar = dynamic_cast<VinPahar *>(meniu.listaBautura[opBautura - 1]);
                for(auto i : meniu.listaBautura){
                    std::cout << i;
                    std::cout << typeid(i).name() << std::endl;
                    std::cout << typeid(VinPahar *).name() << " ----"<< typeid(Bautura).name() << std::endl;
                     i->printBautura();
                     std::cout << std::endl;
                }
                if(vinPahar){
                    // auxiliar_b = new VinPahar(*dynamic_cast<VinPahar *>(meniu.listaBautura[opBautura - 1]));
                    comandaBautura.push_back(new VinPahar(*vinPahar));
                    int auxCantFixa = (dynamic_cast<VinPahar*>(meniu.listaBautura[opBautura - 1]))->get_cantiate_fixa();
                    std::cout << "Ce cantitate?" << std::endl;
                    std::cout << "Atentie se poate doar o cantitate fixa de " << auxCantFixa << "ml sau multipli ai acesteia!" << std::endl;
                    std::cin >> opCantVinPahar;
                    if(opCantVinPahar < 100){
                        std::cout << "Nu se poate. Se va aduce un pahar de "<< auxCantFixa << "ml!" << std::endl;
                    }
                    if(opCantVinPahar > 100 && opCantVinPahar % auxCantFixa != 0){
                        std::cout << "Se poate, dar se va aduce o cantitate de " << (opCantVinPahar / auxCantFixa) * auxCantFixa << std::endl;
                        (dynamic_cast<VinPahar*>(comandaBautura[countComandaBautura]))->set_pret((opCantVinPahar)/ auxCantFixa * dynamic_cast<VinPahar*>(meniu.listaBautura[opBautura - 1])->get_pret());
                    }
                    if(opCantVinPahar > 100 && opCantVinPahar % auxCantFixa == 0){
                        std::cout << "Nicio problema!" << std::endl;
                        (dynamic_cast<VinPahar*>(comandaBautura[countComandaBautura]))->set_pret((opCantVinPahar)/ auxCantFixa * dynamic_cast<VinPahar*>(meniu.listaBautura[opBautura - 1])->get_pret());
                    }
                    countComandaDesert++;
                }else if(typeid(*(meniu.listaBautura[opBautura - 1])) == typeid(VinPahar)){
                    auxiliar_b = new VinSticla(*dynamic_cast<VinSticla *>(meniu.listaBautura[opBautura - 1]));
                    comandaBautura.push_back(auxiliar_b);
                    countComandaBautura++;
                }else if(Bere *bere = dynamic_cast<Bere *>(meniu.listaBautura[opBautura - 1])){
                    // auxiliar_b = new Bere(*bere));
                    comandaBautura.push_back(new Bere(*bere));
                    std::cout << "BA E OK!!!!" << std::endl;
                    countComandaBautura++;
                }else if(typeid(*(meniu.listaBautura[opBautura - 1])) == typeid(Apa)){
                    auxiliar_b = new Apa(*dynamic_cast<Apa *>(meniu.listaBautura[opBautura - 1]));
                    comandaBautura.push_back(auxiliar_b);
                    countComandaBautura++;
                }
            }
        }
        break;
    default:
        break;
    }
    flag = 1;
    std::cout << "Ce ati dori sa mancati?" << std::endl;
    std::cout << "Atentie garnitura poate fi servita doar la fel principal!" << std::endl;
    while(flag){
        for(int i = 0; i < meniu.listaMancare.size(); i++)
            std::cout << i + 1 << ". " << meniu.listaMancare[i]->get_denumire() << std::endl;
        std::cout << meniu.listaMancare.size() + 1 << ". Atat!" << std::endl;
        std::cout << "Se va citi optiunea" << std::endl;
        std::cin >> opMancare;
        if(opMancare == meniu.listaMancare.size() + 1){
            flag = 0;
        }else if(opMancare < 1 || opMancare > meniu.listaMancare.size() + 1){
            std::cout << "Optiune incorecta. Se va opri citirea!" << std::endl;
            flag = 0;
        }else{
            if((typeid(*meniu.listaMancare[opMancare - 1]) == typeid(Cartofi) || typeid(*meniu.listaMancare[opMancare - 1]) == typeid(Orez)) && flagGarnitura == false){
                std::cout << "Nu putem servi garnitura fara un fel principal!" << std::endl;
            }
            if(typeid(*(meniu.listaMancare[opMancare - 1])) == typeid(Ciorba)){
                auxiliar_m = new Ciorba(*dynamic_cast<Ciorba *>(meniu.listaMancare[opMancare - 1]));
                comandaMancare.push_back(auxiliar_m);
                std::cout << "Doriti Ardei?" << std::endl;
                std::cout << "1. Da" << std::endl;
                std::cout << "2. Nu" << std::endl;
                std::cin >> opArdei;
                if(opArdei == 1){
                    dynamic_cast<Ciorba *>(comandaMancare[countComandaMancare])->set_ardei(true);
                } 
                std::cout << "Doriti Smantana?" << std::endl;
                std::cout << "1. Da" << std::endl;
                std::cout << "2. Nu" << std::endl;
                std::cin >> opSmantana;
                if(opSmantana == 1){
                    dynamic_cast<Ciorba *>(comandaMancare[countComandaMancare])->set_smantana(true);
                }
                countComandaMancare++;
            }else if(typeid(*(meniu.listaMancare[opMancare - 1])) == typeid(Vita)){
                auxiliar_m = new Vita(*dynamic_cast<Vita *>(meniu.listaMancare[opMancare - 1]));
                comandaMancare.push_back(auxiliar_m);
                std::cout << "Cum doriti sa fie carnea?" << std::endl;
                std::cout << "1. In sange" << std::endl;
                std::cout << "2. Medie" << std::endl;
                std::cout << "3. Bine facuta" << std::endl;
                std::cin >> opVita;
                if(opVita > 3 || opVita < 1){
                    std::cout <<"Optiune incorecta!";
                }else{
                    dynamic_cast<Vita*>(comandaMancare[countComandaMancare])->set_modPreparare(opVita - 1);
                }
                flagGarnitura = true;
                countComandaMancare++;
            }else if(typeid(*(meniu.listaMancare[opMancare - 1])) == typeid(Pui)){
                auxiliar_m = new Pui(*dynamic_cast<Pui *>(meniu.listaMancare[opMancare - 1]));
                comandaMancare.push_back(auxiliar_m);
                countComandaMancare++;
                flagGarnitura = true;
            }else if(typeid(*(meniu.listaMancare[opMancare - 1])) == typeid(Supa)){
                auxiliar_m = new Supa(*dynamic_cast<Supa *>(meniu.listaMancare[opMancare - 1]));
                comandaMancare.push_back(auxiliar_m);
                countComandaMancare++;
            }else if(typeid(*(meniu.listaMancare[opMancare - 1])) == typeid(Cartofi) && flagGarnitura == true){
                auxiliar_m = new Cartofi(*dynamic_cast<Cartofi *>(meniu.listaMancare[opMancare - 1]));
                comandaMancare.push_back(auxiliar_m);
                countComandaMancare++;
            }else if(typeid(*(meniu.listaMancare[opMancare - 1])) == typeid(Orez) && flagGarnitura == true){
                auxiliar_m = new Orez(*dynamic_cast<Orez *>(meniu.listaMancare[opMancare - 1]));
                comandaMancare.push_back(auxiliar_m);
                countComandaMancare++;
            }
            //countComandaMancare++;
        }
    }
    flag = 1;
    std::cout << "Desert doriti?" << std::endl;
    std::cout << "1. Da" << std::endl;
    std::cout << "2. Nu" << std::endl;
    std::cin >> op;
    if(op == 1){
        while(flag){
            std::cout << "Lista Deserturi:" << std::endl;
            for(int i = 0; i < meniu.listaDesert.size(); i++)
                std::cout << i + 1 << ". " << meniu.listaDesert[i]->get_denumire() << std::endl;
            std::cout << meniu.listaDesert.size() + 1 << ". Atat!" << std::endl;
            std::cin >> opDesert;
            if(opDesert == meniu.listaDesert.size() + 1){
                flag = 0;
            }else if(opDesert < 1 || opDesert > meniu.listaDesert.size() + 1){
                std::cout << "Optiune incorecta. Se va opri citirea!" << std::endl;
                flag = 0;
            }else{
                if(typeid(*meniu.listaDesert[opDesert - 1]) == typeid(Inghetata)){
                    auxiliar_d = new Inghetata(*dynamic_cast<Inghetata *>(meniu.listaDesert[opDesert - 1]));
                    comandaDesert.push_back(auxiliar_d);
                    std::cout << "Cate cupe ati dori?" << std::endl;
                    std::cin >> opCupe;
                    dynamic_cast<Inghetata*>(comandaDesert[countComandaDesert])->set_nrCupe(opCupe);
                    countComandaDesert++;
                }else if(typeid(*meniu.listaDesert[opDesert - 1]) == typeid(Tort)){
                    auxiliar_d = new Tort(*dynamic_cast<Tort *>(meniu.listaDesert[opDesert - 1]));
                    comandaDesert.push_back(auxiliar_d);
                    countComandaDesert++;
                }
            }
        }
    }
}

void Comanda::calculeazaNota(){
    for(int i = 0; i < comandaBautura.size(); i++)
        if(typeid(*(comandaBautura[i])) == typeid(Apa)){
            notaDePlata += dynamic_cast<Apa *>(comandaBautura[i])->get_pret();
        }else if(typeid(*(comandaBautura[i])) == typeid(Bere)){
            notaDePlata += dynamic_cast<Bere *>(comandaBautura[i])->get_pret();
        }else if(typeid(*(comandaBautura[i])) == typeid(VinPahar)){
            notaDePlata += dynamic_cast<VinPahar *>(comandaBautura[i])->get_pret();
        }else if(typeid(*(comandaBautura[i])) == typeid(VinSticla)){
            notaDePlata += dynamic_cast<VinSticla *>(comandaBautura[i])->get_pret();
        }
    for(int i = 0; i < comandaDesert.size(); i++)
        if(typeid(*(comandaDesert[i])) == typeid(Inghetata)){
            notaDePlata += dynamic_cast<Inghetata *>(comandaDesert[i])->get_pret();
        }else if(typeid(*(comandaDesert[i])) == typeid(Tort)){
            notaDePlata += dynamic_cast<Tort *>(comandaDesert[i])->get_pret();
        }
    for(int i = 0; i < comandaMancare.size(); i++)
        if(typeid(*(comandaMancare[i])) == typeid(Vita)){
            notaDePlata += dynamic_cast<Vita *>(comandaMancare[i])->get_pret();
        }else if(typeid(*(comandaMancare[i])) == typeid(Pui)){
            notaDePlata += dynamic_cast<Pui *>(comandaMancare[i])->get_pret();
        }else if(typeid(*(comandaMancare[i])) == typeid(Ciorba)){
            notaDePlata += dynamic_cast<Ciorba *>(comandaMancare[i])->get_pret();
        }else if(typeid(*(comandaMancare[i])) == typeid(Supa)){
            notaDePlata += dynamic_cast<Supa *>(comandaMancare[i])->get_pret();
        }else if(typeid(*(comandaMancare[i])) == typeid(Cartofi)){
            notaDePlata += dynamic_cast<Cartofi *>(comandaMancare[i])->get_pret();
        }else if(typeid(*(comandaMancare[i])) == typeid(Orez)){
            notaDePlata += dynamic_cast<Orez*>(comandaMancare[i])->get_pret();
        }
        //notaDePlata += comandaMancare[i]->get_pret();
}

Comanda & Comanda::operator = (const Comanda &other){
    if(this != &other){
        for(auto &i : comandaMancare)
            delete i;
        comandaMancare.clear();
        
        for(auto &i : comandaDesert)
            delete i;
        comandaDesert.clear();
        
        for(auto &i : comandaBautura)
            delete i;
        comandaBautura.clear();
        comandaBautura = other.comandaBautura;
        comandaDesert = other.comandaDesert;
        comandaMancare = other.comandaMancare;
        countComandaBautura = other.countComandaBautura;
        countComandaDesert = other.countComandaDesert;
        countComandaMancare = other.countComandaMancare;
        notaDePlata = other.notaDePlata;
        meniu = other.meniu;   
    }
    return *this;
}

std::istream & operator >> (std::istream &in, Comanda &prod){
    in >> prod.meniu;
    prod.setComanda();
    return in;
}

std::ostream & operator << (std::ostream &out, Comanda &prod){
    out << "Comanda dumneavoastra:" << std::endl;
    out << "-- Bauturi --" << std::endl;
    for(int i = 0; i < prod.comandaBautura.size(); i++)
        if(typeid(*(prod.comandaBautura[i])) == typeid(Apa)){
            out << *dynamic_cast<Apa *>(prod.comandaBautura[i]) << std::endl;
        }else if(typeid(*(prod.comandaBautura[i])) == typeid(Bere)){
            out << *dynamic_cast<Bere *>(prod.comandaBautura[i]) << std::endl;
        }else if(typeid(*(prod.comandaBautura[i])) == typeid(VinPahar)){
            out << *dynamic_cast<VinPahar *>(prod.comandaBautura[i]) << std::endl;
        }else if(typeid(*(prod.comandaBautura[i])) == typeid(VinSticla)){
            out << *dynamic_cast<VinSticla *>(prod.comandaBautura[i]) << std::endl;
        }
    out << "-- Mancare --" << std::endl;
    for(int i = 0; i < prod.comandaMancare.size(); i++)
        if(typeid(*(prod.comandaMancare[i])) == typeid(Ciorba)){
            out << *dynamic_cast<Ciorba *>(prod.comandaMancare[i]) << std::endl;
        }else if(typeid(*(prod.comandaMancare[i])) == typeid(Supa)){
            out << *dynamic_cast<Supa *>(prod.comandaMancare[i]) << std::endl;
        }else if(typeid(*(prod.comandaMancare[i])) == typeid(Vita)){
            out << *dynamic_cast<Vita *>(prod.comandaMancare[i]) << std::endl;
        }else if(typeid(*(prod.comandaMancare[i])) == typeid(Pui)){
            out << *dynamic_cast<Pui *>(prod.comandaMancare[i]) << std::endl;
        }else if(typeid(*(prod.comandaMancare[i])) == typeid(Cartofi)){
            out << *dynamic_cast<Cartofi *>(prod.comandaMancare[i]) << std::endl;
        }else if(typeid(*(prod.comandaMancare[i])) == typeid(Orez)){
            out << *dynamic_cast<Orez *>(prod.comandaMancare[i]) << std::endl;
        }
    out << "-- Desert --" << std::endl;
    for(int i = 0; i < prod.comandaDesert.size(); i++)
        if(typeid(*(prod.comandaDesert[i])) == typeid(Tort)){
            out << *dynamic_cast<Tort *>(prod.comandaDesert[i]) << std::endl;
        }else if(typeid(*(prod.comandaDesert[i])) == typeid(Inghetata)){
            out << *dynamic_cast<Inghetata *>(prod.comandaDesert[i]) << std::endl;
        }
    out << "!!!-- Nota de plata --!!!" << std::endl;
    out << "      " << prod.notaDePlata << "     " << std::endl;
    return out;
}

void Comanda::afiseazaComanda(){
    for(int i = 0; i < countComandaBautura; i++){
        std::cout << comandaBautura[i]->get_denumire() << " ==== " << comandaBautura[i]->get_pret() << std::endl;
        notaDePlata += comandaBautura[i]->get_pret();
    }
    for(int i = 0; i < countComandaMancare; i++){
        std::cout << comandaMancare[i]->get_denumire() << " ==== " << comandaMancare[i]->get_pret() << std::endl;
        notaDePlata += comandaBautura[i]->get_pret();
    }
    for(int i = 0; i < countComandaDesert; i++){
        std::cout << comandaDesert[i]->get_denumire() << " ==== " << comandaDesert[i]->get_pret() << std::endl;
        notaDePlata += comandaBautura[i]->get_pret();
    }
}

Comanda::~Comanda(){
    for(auto &i : comandaMancare)
        delete i;
    comandaMancare.clear();
        
    for(auto &i : comandaDesert)
        delete i;
    comandaDesert.clear();
        
    for(auto &i : comandaBautura)
        delete i;
    comandaBautura.clear();
    countComandaBautura = countComandaDesert = countComandaMancare = 0;
}