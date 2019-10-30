#include <bits/stdc++.h>
#include "vectorGraf.h"

vectorGraf::vectorGraf(){
    length = 0;
    vectorGrafPonderat = nullptr;
}

vectorGraf::vectorGraf(int n){
    vectorGrafPonderat = new Graf_ponderat[n];
}

std::istream & operator >> (std::istream &in, vectorGraf & VectorGraf){
    in >> VectorGraf.length;
    VectorGraf.vectorGrafPonderat = new Graf_ponderat[VectorGraf.length];
    for(int i = 0; i < VectorGraf.length; i++)
        in >> VectorGraf.vectorGrafPonderat[i];
    return in;
}

std::ostream & operator << (std::ostream &out, vectorGraf & VectorGraf){
    if(VectorGraf.length == 0){
        out << "Vectorul nu a fost initializat" << std::endl;
    }else{
        for(int i = 0; i < VectorGraf.getLength(); i++)
            out << VectorGraf.vectorGrafPonderat[i];
    }
    return out;
}

vectorGraf::~vectorGraf(){
    delete[] vectorGrafPonderat;
}