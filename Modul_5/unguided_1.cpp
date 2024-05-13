#include <iostream>
#include <vector>
using namespace std;

// Struktur data untuk menyimpan data mahasiswa
struct Mahasiswa {
    long long nim;
    int nilai;
};

// Ukuran hash table
const int SIZE = 10;

// Hash table untuk menyimpan data mahasiswa
vector<Mahasiswa> hashTable[SIZE];

// Fungsi hash sederhana
int hashFunction(long long nim) {
    return nim % SIZE;
}

// Fungsi untuk menambahkan data mahasiswa ke hash table
void tambahData(long long nim, int nilai) {
    int index = hashFunction(nim);
    hashTable[index].push_back({nim, nilai});
}

// Fungsi untuk menghapus data mahasiswa dari hash table berdasarkan NIM
void hapusData(long long nim) {
    int index = hashFunction(nim);
    for (int i = 0; i < hashTable[index].size(); i++) {
        if (hashTable[index][i].nim == nim) {
            hashTable[index].erase(hashTable[index].begin() + i);
            break;
        }
    }
}

// Fungsi untuk mencari data mahasiswa berdasarkan NIM
void cariByNIM(long long nim) {
    int index = hashFunction(nim);
    for (int i = 0; i < hashTable[index].size(); i++) {
        if (hashTable[index][i].nim == nim) {
            cout << "Data ditemukan - NIM: " << hashTable[index][i].nim << ", Nilai: " << hashTable[index][i].nilai << endl;
            return;
        }
    }
    cout << "Data tidak ditemukan." << endl;
}

// Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai
void cariByNilai(int minNilai, int maxNilai) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < hashTable[i].size(); j++) {
            if (hashTable[i][j].nilai >= minNilai && hashTable[i][j].nilai <= maxNilai) {
                cout << "NIM: " << hashTable[i][j].nim << ", Nilai: " << hashTable[i][j].nilai << endl;
            }
        }
    }
}

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "Menu: \n";
    cout << "1. Tambah Data Mahasiswa\n";
    cout << "2. Hapus Data Mahasiswa\n";
    cout << "3. Cari Data Mahasiswa berdasarkan NIM\n";
    cout << "4. Cari Data Mahasiswa berdasarkan Rentang Nilai (80 - 90)\n";
    cout << "5. Keluar\n";
}

int main() {
    int pilihan;
    long long nim; // Menggunakan long long untuk menampung NIM 10 digit
    do {
        tampilkanMenu();
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int nilai;
                cout << "Masukkan NIM (10 digit): ";
                cin >> nim;
                while (nim < 1000000000 || nim > 9999999999) {
                    cout << "NIM harus 10 digit. Silakan masukkan lagi: ";
                    cin >> nim;
                }
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahData(nim, nilai);
                break;
            }
            case 2: {
                cout << "Masukkan NIM yang akan dihapus (10 digit): ";
                cin >> nim;
                while (nim < 1000000000 || nim > 9999999999) {
                    cout << "NIM harus 10 digit. Silakan masukkan lagi: ";
                    cin >> nim;
                }
                hapusData(nim);
                break;
            }
            case 3: {
                cout << "Masukkan NIM yang akan dicari (10 digit): ";
                cin >> nim;
                while (nim < 1000000000 || nim > 9999999999) {
                    cout << "NIM harus 10 digit. Silakan masukkan lagi: ";
                    cin >> nim;
                }
                cariByNIM(nim);
                break;
            }
            case 4: {
                cariByNilai(80, 90);
                break;
            }
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}