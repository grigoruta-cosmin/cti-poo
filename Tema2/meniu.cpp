#include "meniu.h"

Meniu::Meniu(int countListaMancare = 0, int countListaBautura = 0, int countListaDesert = 0){
    // for(int i = 0; i < countListaBautura; i++){
    //     listaBautura.push_back(new Bautura());
    // }
    // for(int i = 0; i < countListaMancare; i++){
    //     listaMancare.push_back(new Mancare());
    // }
    // for(int i = 0; i < countListaDesert; i++){
    //     listaDesert.push_back(new Desert());
    // }
}

Meniu::Meniu(const Meniu & other){
    for(auto &i : other.listaMancare)
        listaMancare.push_back(new Mancare(*i));
    for(auto &i : other.listaBautura)
        listaBautura.push_back(new Bautura(*i));
    for(auto &i : other.listaDesert)
        listaDesert.push_back(new Desert(*i));
    countListaBautura = other.countListaBautura;
    countListaDesert = other.countListaDesert;
    countListaMancare = other.countListaMancare;    
}

std::istream & operator >> (std::istream &in, Meniu &prod){
    int opt;
    Mancare *auxiliar;
    std::cout << "Intoruceti numarul de elemente in lista de mancare: " << std::endl;
    in >> prod.countListaMancare;
    for(int i = 0; i < prod.countListaMancare; i++){
        std::cout << "1. Ciorba" << std::endl;
        std::cout << "2. Supa" << std::endl;
        std::cout << "3. Pui" << std::endl;
        std::cout << "4. Vita" << std::endl;
        std::cout << "5. Cartofi" << std::endl;
        std::cout << "6. Orez" << std::endl;
        std::cout << "Se va citi optiunea" << std::endl;
        in >> opt;
        switch (opt){
        case 1:
            auxiliar = new Ciorba();
            in >> *dynamic_cast<Ciorba *>(auxiliar);
            prod.listaMancare.push_back(auxiliar);
            break;
        case 2:
            auxiliar = new Supa();
            std::cin >> *dynamic_cast<Supa *>(auxiliar);
            prod.listaMancare.push_back(auxiliar);
            break;
        case 3:
            auxiliar = new Pui();
            std::cin >> *dynamic_cast<Pui *>(auxiliar);
            prod.listaMancare.push_back(auxiliar);
            break;
        case 4:
            auxiliar = new Vita();
            std::cin >> *dynamic_cast<Vita *>(auxiliar);
            prod.listaMancare.push_back(auxiliar);
            break;
        case 5:
            auxiliar = new Cartofi();
            std::cin >> *dynamic_cast<Cartofi *>(auxiliar);
            prod.listaMancare.push_back(auxiliar);
            break;
        case 6:
            auxiliar = new Orez();
            std::cin >> *dynamic_cast<Orez *>(auxiliar);
            prod.listaMancare.push_back(auxiliar);
            break;
        default:
            std::cout << "etc" << std::endl;
            break;
        }
    }
    //delete auxiliar;
    std::cout << "Introduceti numarul de elemente in lista de bauturi:" << std::endl;
    Bautura *auxiliar_b;
    in >> prod.countListaBautura;
    for(int i = 0; i < prod.countListaBautura; i++){
        std::cout << "1. Vin la Pahar" << std::endl;
        std::cout << "2. Vin la Sticla" << std::endl;
        std::cout << "3. Bere" << std::endl;
        std::cout << "4. Apa" << std::endl;
        std::cout << "Se va citi optiunea:" << std::endl;
        in >> opt;
        switch(opt){
            case 1:
                auxiliar_b = new VinPahar();
                in >> *dynamic_cast<VinPahar *>(auxiliar_b);
                prod.listaBautura.push_back(auxiliar_b);
                break;
            case 2:
                auxiliar_b = new VinSticla();
                in >> *dynamic_cast<VinSticla *>(auxiliar_b);
                prod.listaBautura.push_back(auxiliar_b);
                break;
            case 3:
                auxiliar_b = new Bere();
                in >> *dynamic_cast<Bere *>(auxiliar_b);
                prod.listaBautura.push_back(auxiliar_b);
                break;
            case 4:
                auxiliar_b = new Apa();
                in >> *dynamic_cast<Apa *>(auxiliar_b);
                prod.listaBautura.push_back(auxiliar_b);
                break;
            default:
                std::cout << "etc" << std::endl;
                break;
        }
    }
    Desert *auxiliar_d;
    std::cout << "Intoruceti numarul pentru lista de deserturi:" << std::endl;
    in >> prod.countListaDesert;
    for(int i = 0; i < prod.countListaDesert; i++){
        std::cout << "1. Inghetata" << std::endl;
        std::cout << "2. Tort" << std::endl;
        std::cout << "Se va citi optiunea" << std::endl;
        in >> opt;
        switch(opt){
            case 1:
                auxiliar_d = new Inghetata();
                in >> *dynamic_cast<Inghetata *>(auxiliar_d);
                prod.listaDesert.push_back(auxiliar_d);
                break;
            case 2:
                auxiliar_d = new Tort();
                in >> *dynamic_cast<Tort *>(auxiliar_d);
                prod.listaDesert.push_back(auxiliar_d);
            break;
            default:
                std::cout << "etc" << std::endl;
        }
    }
    return in;
}

Meniu & Meniu::operator = (const Meniu &other){
    if(this != &other){
        for(auto &i : listaBautura)
            delete i;
        listaBautura.clear();

        for(auto &i : listaDesert)
            delete i;
        listaDesert.clear();

        for(auto &i : listaMancare)
            delete i;
        listaMancare.clear();

        // for(auto &i : other.listaBautura)
        //     listaBautura.push_back(new Bautura(*i));
        // for(auto &i : other.listaMancare)
        //     listaMancare.push_back(new Mancare(*i));
        // for(auto &i : other.listaDesert)
        //     listaDesert.push_back(new Desert(*i));
        listaBautura = other.listaBautura;
        listaDesert = other.listaDesert;
        listaMancare = other.listaMancare;
        countListaBautura = other.countListaBautura;
        countListaDesert = other.countListaDesert;
        countListaMancare = other.countListaMancare;
    }
    return *this;
}

std::ostream & operator << (std::ostream &out, Meniu &prod){
    out << "-- Mancare --" << std::endl;
    for(int i = 0; i < prod.countListaMancare; i++){
        Ciorba * ciorba = dynamic_cast<Ciorba *>(prod.listaMancare[i]);
        if(ciorba){
            out << *ciorba << std::endl;
        }else if(typeid(*(prod.listaMancare[i])) == typeid(Supa)){
            out << *dynamic_cast<Supa *>(prod.listaMancare[i]) << std::endl;
        }else if(typeid(*(prod.listaMancare[i])) == typeid(Pui)){
            out << *dynamic_cast<Pui *>(prod.listaMancare[i]) << std::endl;
        }else if(typeid(*(prod.listaMancare[i])) == typeid(Vita)){
            out << *dynamic_cast<Vita *>(prod.listaMancare[i]) << std::endl;
        }else if(typeid(*(prod.listaMancare[i])) == typeid(Cartofi)){
            out << *dynamic_cast<Cartofi *>(prod.listaMancare[i]) << std::endl;
        }else if(typeid(*(prod.listaMancare[i])) == typeid(Orez)){
            out << *dynamic_cast<Orez *>(prod.listaMancare[i]) << std::endl;
        }
    }
    out << "-- Bautura --" << std::endl;
    for(int i = 0; i < prod.countListaBautura; i++)
        if(typeid(*(prod.listaBautura[i])) == typeid(VinPahar)){
            out << *dynamic_cast<VinPahar *>(prod.listaBautura[i]) << std::endl;
        }else if(typeid(*(prod.listaBautura[i])) == typeid(VinSticla)){
            out << *dynamic_cast<VinSticla *>(prod.listaBautura[i]) << std::endl;
        }else if(typeid(*(prod.listaBautura[i])) == typeid(Bere)){
            out << *dynamic_cast<Bere *>(prod.listaBautura[i]) << std::endl;
        }else if(typeid(*(prod.listaBautura[i])) == typeid(Apa)){
            out << *dynamic_cast<Apa *>(prod.listaBautura[i]) << std::endl;
        }
    out << "-- Desert --" << std::endl;
    for(int i = 0; i < prod.countListaDesert; i++)
        if(typeid(*(prod.listaDesert[i])) == typeid(Inghetata)){
            out << *dynamic_cast<Inghetata *>(prod.listaDesert[i]);
        }else if(typeid(*(prod.listaDesert[i])) == typeid(Tort)){
            out << *dynamic_cast<Tort *>(prod.listaDesert[i]);
        }
    return out;
}

Meniu::~Meniu(){
    for(auto &i : listaBautura)
        delete i;
    //listaBautura.clear();

    for(auto &i : listaDesert)
        delete i;
    //listaDesert.clear();

    for(auto &i : listaMancare)
        delete i;
    //listaMancare.clear();
    countListaBautura = countListaDesert = countListaMancare = 0;
}