#ifndef GRAF_PONDERAT_H
#define GRAF_PONDERAT_H

#include <bits/stdc++.h>
#include "list.h"
#include "muchie_pon.h"

class Graf_ponderat{
    private:
        const int inf = 1000;
        friend class MuchiePon;   
        int nrNoduri;
        int nrMuchii;
        int *vizitat;
        int **matriceAdiacenta;
        int **matricePonderi;
        int **matricePonderiMinime;
        std::vector<MuchiePon> muchii;
        List *listeAdiacenta;
    public:
        Graf_ponderat();
        Graf_ponderat(int);
        Graf_ponderat(const Graf_ponderat&);
        void set_nrNoduri(int data){this->nrNoduri = data;}
        void set_nrMuchii(int data){this->nrMuchii = data;}
        int get_nrNoduri();
        int get_nrMuchii();
        void DFS(int);
        void BFS(int);
        int **get_matriceAdiacenta();
        int **get_matricePonderi();
        void afisareMatrice();
        void descompunDrum(int, int);
        void scriuDrum(int, int);
        void calculeazaMatricePonderiMinime();
        bool verificareConex();
        friend std::ostream & operator <<(std::ostream &, const Graf_ponderat&);
        friend std::istream & operator >>(std::istream &, Graf_ponderat &);
        friend Graf_ponderat operator *(Graf_ponderat&, Graf_ponderat&);
        Graf_ponderat & operator =(const Graf_ponderat&);
        ~Graf_ponderat();
};

#endif