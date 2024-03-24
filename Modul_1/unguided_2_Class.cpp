#include <iostream>
using namespace std;

class Mahasiswa_ITTP{
public:
    string nama;
    unsigned int nim;
    string kelas;
};

int main(){
    Mahasiswa_ITTP mhs;
    mhs.nama = "Naufal Thoriq Muzhaffar";
    mhs.nim = 2311102078;
    mhs.kelas = "IF-11-B";
    cout << "Mahasiswa ITTP (Class)\n";
    cout << "Nama   : " << mhs.nama << endl;
    cout << "NIM    : " << fixed << mhs.nim << endl;
    cout << "Kelas  : " << mhs.kelas;
    return 0;
}