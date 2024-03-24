#include <iostream>
#include <string>
using namespace std;

int pilih;
double a, b;

double penjumlahan(double a, double b){
     return a + b;
}

int main(){
    cout << "Selamat datang di Kalkulator Sederhana";
    cout << "\nManu\n";
    cout << "1. Penjumlahan\n";
    cout << "2. Pengurangan\n";
    cout << "Pilih (1-2): ";
    cin >> pilih;
    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;
    if (pilih == 1){
        cout << "Penjumlahan =";
        penjumlahan(a, b);
        }
    return 0;
}
