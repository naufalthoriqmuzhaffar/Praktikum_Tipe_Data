#include <iostream>
using namespace std;

struct Mahasiswa_ITTP{
    string nama;
    unsigned int nim;
    string kelas;
};

int main(){
    struct Mahasiswa_ITTP mhs;
    mhs.nama = "Naufal Thoriq Muzhaffar";
    mhs.nim = 2311102078;
    mhs.kelas = "IF-11-B";
    cout << "Mahasiswa ITTP (Struct)\n";
    cout << "Nama   : " << mhs.nama << endl;
    cout << "NIM    : " << fixed << mhs.nim << endl;
    cout << "Kelas  : " << mhs.kelas;
    return 0;
}