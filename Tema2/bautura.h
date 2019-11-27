#ifndef BAUTURA_H
#define BAUTURA_H

#include <bits/stdc++.h>

class Bautura{
protected:
    std::string denumire;
    double pret;
public:
    Bautura(double pret = 0, std::string denumire = "") : pret(pret), denumire(denumire){}
    Bautura(const Bautura &);
    double get_pret() const {return pret;}
    void set_pret(double npret){pret = npret;}
    std::string get_denumire() const {return denumire;}
    void printBautura(){std::cout << "ceva" << std::endl;}
    virtual ~Bautura() = default;
};

// Interfatata clasei Bere

class Bere : public Bautura{
    bool alcool; // false fara alcool, true - cu alcool
    const int cantitate_fixa = 500;
public:
    Bere(bool alcool = 1, double pret = 0, std::string denumire = "") : Bautura(pret, denumire), alcool(alcool){}
    Bere(const Bere &);
    double get_pret() const {return pret;}
    const int get_cantitate() const {return cantitate_fixa;}
    bool get_alcool() const{ return alcool;}
    Bere & operator = (const Bere &);
    void printBautura();
    friend std::istream & operator >> (std::istream &, Bere &);
    friend std::ostream & operator << (std::ostream &, Bere &);
    ~Bere() = default;
};

// Interfatata clasei Vin

class Vin : public Bautura{
protected:
    bool tip; // false - alb, true - rosu
public:
    Vin(bool tip = false, double pret = 0, std::string denumire = "") :Bautura(pret, denumire), tip(tip){}
    bool get_tip() const {return tip;}
    virtual ~Vin() = default;
};

// Interfatata clasei VinSticla

class VinSticla : public Vin{
    int an_productie;
    const int cantitate_fixa = 750;
public:
    VinSticla(double pret = 0, bool tip = 0, std::string denumire = "", int an_productie = 0) : Vin(tip, pret, denumire), an_productie(an_productie){}
    VinSticla(const VinSticla &);
    double get_pret() const {return pret;}
    const int get_cantitate_fixa() const {return cantitate_fixa;}
    int get_an_productie() const {return an_productie;}
    //std::string get_marca(){return marca;}
    VinSticla & operator = (const VinSticla &);
    void printBautura();
    friend std::istream & operator >> (std::istream &, VinSticla &);
    friend std::ostream & operator << (std::ostream &, VinSticla &);
    ~VinSticla() = default;
};

// Interfatata clasei VinPahar

class VinPahar : public Vin{
    const int cantitate_fixa = 100;
public:
    VinPahar(double pret = 0, bool tip = false) : Vin(tip, pret, "Vinul Casei"){}
    VinPahar(const VinPahar &);
    double get_pret() const {return pret;}
    const int get_cantiate_fixa() const {return cantitate_fixa;}
    VinPahar & operator = (const VinPahar &);
    void printBautura();
    friend std::istream & operator >> (std::istream &, VinPahar &);
    friend std::ostream & operator << (std::ostream &, VinPahar &);
    ~VinPahar() = default;
};

// Interfatata clasei Apa

class Apa : public Bautura{
    bool carbogazoasa;
public:
    Apa(double pret = 0, bool carbogazoasa = false, std::string denumire = "") : Bautura(pret, denumire), carbogazoasa(carbogazoasa){}
    Apa(const Apa &);
    double get_pret() const {return pret;}
    Apa & operator = (const Apa &);
    void printBautura();
    friend std::istream & operator >>(std::istream &, Apa &);
    friend std::ostream & operator <<(std::ostream &, Apa &);
    ~Apa() = default;
};

#endif