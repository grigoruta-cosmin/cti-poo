#ifndef CONT_H
#define CONT_H
#include <bits/stdc++.h>
#include "data.h"
#include "operatiune.h"

class Cont{
protected:
    static int numarCont;
    int idCont;
    std::string numeDetinator;
    std::vector<Operatiune> istoric;
    Data data;
    double sold;
public:
    Cont(){numarCont++; idCont = numarCont;}
    Cont(std::string numeDetinator, double sold):numeDetinator(numeDetinator), sold(sold){numarCont++; idCont = numarCont; }
    Cont(const Cont &);
    Cont & operator=(const Cont &);
    int getIdCont() const { return idCont; }
    void setIdCont(int idCont) { this->idCont = idCont; }
    std::vector<Operatiune> getIstoric() const { return istoric; }
    std::string getNumeDetinator() const { return numeDetinator; }
    void setNumeDetinator(std::string numeDetinator) { this->numeDetinator = numeDetinator; }
    double getSold() const { return sold; }
    void setSold(double sold) { this->sold = sold; }
    friend std::ostream & operator<<(std::ostream &, const Cont &);
    friend std::istream & operator>>(std::istream &, Cont &);
    virtual void retragere(double);
    virtual void depunere(double);
    void afisareIstoric() const;
    virtual std::istream & read(std::istream &);
    virtual std::ostream & print(std::ostream &) const;
    virtual ~Cont(){numarCont--;}
};

class ContCurent : public Cont{
    int numarTranzactiiGratuite;
    double taxaTranzactieOnline;
    double taxaTranzactieAltBancomat;
public:
    ContCurent() = default;
    ContCurent(std::string numeDetinator, double sold, int numarTranzactiiGratuite, double taxaTranzactieAltBancomat, double taxaTranzactieOnline):
        Cont(numeDetinator, sold), numarTranzactiiGratuite(numarTranzactiiGratuite), taxaTranzactieAltBancomat(taxaTranzactieAltBancomat), taxaTranzactieOnline(taxaTranzactieOnline){}
    ContCurent(const ContCurent &);
    ContCurent & operator=(const ContCurent &);
    int getNumarTranzactiiGratuite() const { return numarTranzactiiGratuite; }
    void setNumarTranzactiiGratuite(int numar) { numarTranzactiiGratuite = numar; }
    double getTaxaTranzactieBancomat() const { return taxaTranzactieAltBancomat; }
    void setTaxaTranzactieBancomat(double taxa) { taxaTranzactieAltBancomat = taxa; }
    double getTaxaTranzactieOnline() const { return taxaTranzactieOnline; }
    void depunereContCurent(double);
    void retragereContCurent(double);
    void plataOnline(double);
    void retragereAltBancomat(double);
    virtual std::ostream & print(std::ostream &) const override;
    virtual std::istream & read(std::istream &) override;
    ~ContCurent() = default;
};

class ContEconomii : public Cont{
    int tipulDobanzii;
    double dobanda;
    Data dataScadenta;
    Data ultimaDataActualizare;
public:
    ContEconomii() = default;
    ContEconomii(std::string numeDetinator, double sold, int tipulDobanzii, double dobanda) : Cont(numeDetinator, sold), tipulDobanzii(tipulDobanzii), dobanda(dobanda){}
    ContEconomii(const ContEconomii&);
    ContEconomii & operator=(const ContEconomii&);
    int getTipulDobanzii() const { return tipulDobanzii; }
    void setTipulDobanzii(int tip){ tipulDobanzii = tip; }
    void adaugaDobanda();
    virtual void depunere(double);
    virtual void retragere(double);
    void tranzactie(int);
    virtual std::ostream & print(std::ostream &) const override;
    virtual std::istream & read(std::istream &) override;
    ~ContEconomii() = default;
};
#endif