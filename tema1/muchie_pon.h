#ifndef MUCHIE_PON_H
#define MUCHIE_PON_H

#include <bits/stdc++.h>

class MuchiePon{
    int a,b,pond;
    public:
        MuchiePon(int a = 0, int b = 0, int pond = 0){
            this->a = a;
            this->b = b;
            this->pond = pond;
        }
        MuchiePon(const MuchiePon&);
        int get_a(){return a;}
        int get_b(){return b;}
        int get_pondere(){return pond;}
        void afis() const {std::cout << a << " " << b << " " << pond << std::endl;}
        MuchiePon & operator =(const MuchiePon &);
        friend bool comp(const MuchiePon &, const MuchiePon &);
};

#endif