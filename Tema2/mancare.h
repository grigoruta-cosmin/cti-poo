#ifndef MANCARE_H
#define MANCARE_H

#include <bits/stdc++.h>

class Mancare{
protected:
    double pret;
    std::string denumire;
public:
    Mancare(std::string denumire = "", double pret = 0) : denumire(denumire), pret(pret){}
    Mancare(const Mancare &);
    void set_denumire(std::string denumire){this->denumire = denumire;}
    std::string get_denumire() const { return denumire;}
    double get_pret() const {return pret;}
    void set_pret(double pret){this->pret = pret;}
    void printPreparat(){std::cout << "ceva" << std::endl;}
    virtual ~Mancare() = default;
};

// Interfata clasei Ciorba

class Ciorba : public Mancare{
protected:
    bool smantana;
    bool ardei;
public:
    Ciorba(std::string denumire = "", double pret = 0, bool ardei = false, bool smantana = false) : Mancare(denumire, pret), smantana(smantana), ardei(ardei){} 
    Ciorba(const Ciorba&);
    bool get_smantana() const {return smantana;}
    bool get_ardei() const {return ardei;}
    void set_smantana(bool);
    void set_ardei(bool);
    Ciorba & operator = (const Ciorba &);
    void printPreparat();
    friend std::istream & operator >>(std::istream &, Ciorba &);
    friend std::ostream & operator <<(std::ostream &, Ciorba &);
    ~Ciorba() = default;
};

// Interfata clasei Supa

class Supa : public Mancare{
public:
    Supa(std::string denumire = "", double pret = 0) : Mancare(denumire, pret) {}
    Supa(const Supa &);
    Supa & operator = (const Supa &);
    void printPreparat();
    friend std::istream & operator >> (std::istream &, Supa &);
    friend std::ostream & operator << (std::ostream &, Supa &);
    ~Supa() = default;
};

// Interfata clasei Pui

class Pui : public Mancare{
public:
    Pui(std::string denumire = "",  double pret = 0) : Mancare(denumire, pret){}
    Pui(const Pui &);
    Pui & operator = (const Pui &);
    void printPreparat();
    friend std::istream & operator >> (std::istream &, Pui &);
    friend std::ostream & operator << (std::ostream &, Pui &);
    ~Pui() = default;
};

// Interfata clasei Vita

class Vita : public Mancare{
    int modPreparare; // 0 - in sange, 1 - mediu, 2- bine facut
public:
    Vita(int modPreparare = 0, std::string denumire = "",  double pret = 0) : Mancare(denumire, pret), modPreparare(modPreparare) {}
    Vita(const Vita &);
    Vita & operator = (const Vita &);
    void printPreparat();
    friend std::istream & operator >> (std::istream &, Vita &);
    friend std::ostream & operator << (std::ostream &, Vita &);
    int get_modPreparare(){return modPreparare;}
    void set_modPreparare(int);
    ~Vita() = default;
};

// Interfata clasei Desert

class Desert{
protected:
    std::string denumire;
    double pret;
public:
    Desert(std::string denumire = "", double pret = 0) : denumire(denumire), pret(pret){} 
    Desert(const Desert &);
    void printDesert(){std::cout << "ceva ceva " << std::endl;}
    std::string get_denumire() const {return denumire;}
    double get_pret() const {return pret;}
    virtual ~Desert() = default;
};

// Interfata clasei Inghetata

class Inghetata : public Desert{
    int nrCupe;
public:
    Inghetata(std::string denumire = "", double pret = 0, int nrCupe = 3) : Desert(denumire, pret), nrCupe(nrCupe) {}
    Inghetata(const Inghetata &);
    Inghetata & operator = (const Inghetata &);
    void printDesert();
    friend std::istream & operator >> (std::istream &, Inghetata &);
    friend std::ostream & operator << (std::ostream &, Inghetata &);
    void set_nrCupe(int);
    ~Inghetata() = default;
};

// Interfata clasei Tort
class Tort : public Desert{
public:
    Tort(std::string denumire = "", double pret = 0) : Desert(denumire, pret){}
    Tort(const Tort &);
    Tort & operator = (const Tort &);
    void printDesert();
    friend std::istream & operator >> (std::istream &, Tort &);
    friend std::ostream & operator << (std::ostream &, Tort &);
    void set_nrFelii(int);
    ~Tort() = default;
};

// Interfata clasei Cartofi

class Cartofi : public Mancare{
public:
    Cartofi(double pret = 0, std::string denumire = "") : Mancare(denumire, pret){}
    Cartofi(const Cartofi &);
    Cartofi & operator = (const Cartofi &);
    void printPreparat();
    friend std::istream & operator >> (std::istream &, Cartofi &);
    friend std::ostream & operator << (std::ostream &, Cartofi &);
    ~Cartofi() = default;
};

// Interfata clasei Orez

class Orez : public Mancare{
public:
    Orez(double pret = 0, std::string denumire = "") : Mancare(denumire, pret) {}
    Orez(const Orez &);
    Orez & operator = (const Orez &);
    void printPreparat();
    friend std::istream & operator >> (std::istream &, Orez &);
    friend std::ostream & operator << (std::ostream &, Orez &);
    ~Orez() = default;
};

#endif