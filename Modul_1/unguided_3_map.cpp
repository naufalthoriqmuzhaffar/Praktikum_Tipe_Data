#include <iostream>
#include <map>
#include <string>
using namespace std;

int main (){
    map <string, string> Mahasiswa_ITTP;
    Mahasiswa_ITTP["1.Nama    : "] = "Naufal Thoriq Muzhaffar";
    Mahasiswa_ITTP["2.NIM     : "] = "2311102078";
    Mahasiswa_ITTP["3.Kelas   : "] = "IF-11-B";
    map<string, string>::iterator it = Mahasiswa_ITTP.begin();
    cout << "Mahasiswa ITTP (map)\n";
    while (it != Mahasiswa_ITTP.end()) {
        cout << it -> first << it -> second << endl;
        ++it;
    }
    return 0;
}