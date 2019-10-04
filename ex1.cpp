#include <iostream>

using namespace std;

int getSumaDivPropriiSiUnu(long int a){
    int suma = 0;
    for(long int i = 2; i <= a / 2; i ++){
        if(a % i == 0){
            suma += i;
        }
    }
    suma ++;
    return suma;
}

int main(){
    long int a, b;
    cin >> a >> b;
    for(long int i = a; i <= b; i++){
        if(i == getSumaDivPropriiSiUnu(i))
            cout << i << endl;
    }
    return 0;
}