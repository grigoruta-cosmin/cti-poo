#include <iostream>
#include <string>

using namespace std;

class Curs{
    string denumire;
    public:
        void setDenumire(string);
        string getDenumire();
};

void Curs::setDenumire(string den){
    denumire = den;
}

string Curs::getDenumire(){
    return denumire;
}

class Student{
    int grupa;
    string nume;
    Curs C;
    public:
        Student(string, int);
        void setCurs(string);
        void afis();
};

void Student::setCurs(string den){
    C.setDenumire(den);
}

Student::Student(string n, int g){
    grupa = g;
    nume = n;
}

void Student::afis(){
    cout << "Numele Studentului si Grupa: " << nume << " " << grupa << endl;
    cout << "Participa la cursul de: " << C.getDenumire() << endl;
}

int main(){
    Student a("Cosmin", 252);
    a.setCurs("POO");
    a.afis();
    return 0;
}