# Tema 1 Programarea Orientata pe Obiect

## Graf Ponderat

Implementare in C++ folosind clase

ATENTIE: functiile pe care le-am numit mai jos metode (fie ca sunt
supraincarcari de operatori, fie altfel de functii), pot fi implementate ca functii
prieten in loc de metode ale claselor respective, daca se considera ca aceasta alegere
este mai naturala

Supraincarcarea operatorilor `<<` si `>>` pentru iesiri si intrari de obiecte,
dupa indicatiile de mai jos, astfel incat sa fie permise (si ilustrate in program) :heavy_check_mark:

Sa existe o metoda publica prin care se realizeaza citirea informațiilor
complete a n obiecte, memorarea și afisarea acestora :heavy_check_mark:

- constructori de inițializare și de copiere:heavy_check_mark:
- destructor:heavy_check_mark:
- metoda publica pentru afisarea grafului, care sa supraincarce operatorul `<<` și
sa ilustreze toate modalitatile de reprezentare a grafului:heavy_check_mark:
- parcurgerea in latime:heavy_check_mark:
- parcurgerea in adancime:heavy_check_mark:
- determinarea matricii ponderilor drumurilor cu ponderi minime:heavy_check_mark:
- determinarea nodurilor intermediare de pe drumul de pondere minima intre
doua noduri:heavy_check_mark:
- o metoda care sa determine daca graful este conex, care poate folosi oricare
dintre metodele anterioare:heavy_check_mark:
- o metoda de supraincarcare a operatorului `*`, care sa determine, din doua
grafuri ponderate avand aceeasi multime de noduri, graful ponderat cu aceeasi
multime de noduri ca si acele doua grafuri, si cu multimea muchiilor egala cu
intersectia multimilor muchiilor celor doua grafuri, cu fiecare muchie avand ca pondere
minimul dintre ponderile muchiilor corespunzatoare din acele doua grafuri :heavy_check_mark:
