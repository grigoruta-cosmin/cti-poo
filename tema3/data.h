#ifndef DATA_H
#define DATA_H
#include <bits/stdc++.h>
template<class A, class B, class C>
class Triplet{
    A a;
    B b;
    C c;
public:
    Triplet() = default;
    Triplet(const Triplet<A, B, C> &);
    Triplet<A, B, C> & operator=(const Triplet<A, B, C> &);
    bool operator<(const Triplet<A, B, C> &) const;
    A getFirst() const { return a; }
    B getSecond() const { return b; }
    C getThird() const { return c; }
    Triplet<A, B, C> operator-(const Triplet<A, B, C> &other){
        Triplet<A, B, C> res;
        res.c = c - other.c;
        res.b = b - other.b;
        res.a = a - other.a;
        if(res.a < 1){
            res.a = 30 - res.a - 1;
            res.b--;
        }
        if(res.b < 1){
            res.b = 12 - res.b - 1;
            res.c--;
        }
        return res;
    }
    friend std::ostream & operator<<(std::ostream &os, const Triplet<A, B, C> &other){
        os << other.a << "." << other.b << "." << other.c << "\n";
        return os;
    }
    friend std::istream & operator>>(std::istream &os, Triplet<A, B, C> &other){
        std::cout <<"Ziua: " << std::endl;
        os >> other.a;
        std::cout <<"Luna: " << std::endl;
        os >> other.b;
        std::cout <<"Anul: " << std::endl;
        os >> other.c;
        return os;        
    }
    ~Triplet() = default;
};

template<class A, class B, class C>
Triplet<A, B, C>::Triplet(const Triplet<A, B, C> &other){
    a = other.a;
    b = other.b;
    c = other.c;
}

template<class A, class B, class C>
Triplet<A, B, C> & Triplet<A, B, C>::operator=(const Triplet<A, B, C> &other){
    if(this != &other){
        a = other.a;
        b = other.b;
        c = other.c;
    }  
    return *this;
}

template<class A, class B, class C>
bool Triplet<A, B, C>::operator<(const Triplet<A, B, C> &other) const {
    if(c < other.c){
        return true;
    }else if(c > other.c){
        return false;
    }else{
        if(b < other.b){
            return true;
        }else if(b > other.b){
            return false;
        }else{
            if(a < other.a){
                return true;
            }else{
                return false;
            }
        }
    }
}

using Data = Triplet<int, int, int>;
#endif