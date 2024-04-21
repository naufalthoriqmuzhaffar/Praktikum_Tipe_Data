#include <iostream>
#include <iomanip>
using namespace std;
struct mahasiswa
{
    string nama;
    string nim;
};
struct node
{
    mahasiswa ITTP;
    node *next;
};
node *head, *tail, *bantu, *hapus, *before, *baru;
void init()
{
    head = NULL;
    tail = NULL;
}
bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
mahasiswa Pendataan()
{
    mahasiswa ITTP;
    cout << "\nMasukkan Nama\t: ";
    cin.ignore();
    getline(cin, ITTP.nama);
    cout << "Masukkan NIM\t: ";
    cin >> ITTP.nim;
    return ITTP;
}
void insertDepan(mahasiswa ITTP)
{
    node *baru = new node;
    baru->ITTP.nama = ITTP.nama;
    baru->ITTP.nim = ITTP.nim;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
    cout << "Data " << ITTP.nama << " berhasil diinput!\n";
}
void insertBelakang(mahasiswa ITTP)
{
    node *baru = new node;
    baru->ITTP.nama = ITTP.nama;
    baru->ITTP.nim = ITTP.nim;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
int hitungList()
{
    int penghitung = 0;
    node *bantu;
    bantu = head;
    while (bantu != NULL)
    {
        penghitung++;
        bantu = bantu->next;
    }
    return penghitung;
}
void insertTengah(mahasiswa identitas, int posisi)
{
    node *baru = new node;
    baru->ITTP.nama = identitas.nama;
    baru->ITTP.nim = identitas.nim;
    node *bantu;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "posisi diluar jangakauan";
    }
    else if (posisi == 1)
    {
        cout << "INi bukan posisi tengah\n";
    }
    else
    {
        bantu = head;
        int penghitung = 1;
        while (penghitung != posisi - 1)
        {
            penghitung++;
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
void ubahDepan(mahasiswa data)
{
    string namaBefore = head->ITTP.nama;
    head->ITTP.nama = data.nama;
    head->ITTP.nim = data.nim;
    cout << "data " << namaBefore << " telah diganti dengan data " << data.nama
         << endl;
}
void ubahBelakang(mahasiswa data)
{
    string namaBefore = tail->ITTP.nama;
    tail->ITTP.nama = data.nama;
    tail->ITTP.nim = data.nim;
    cout << "data " << namaBefore << " telah diganƟ dengan data " << data.nama
         << endl;
}
void ubahTengah(mahasiswa data)
{
    int posisi;
    cout << "\nMasukkan posisi data yang akan diubah : ";
    cin >> posisi;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "\nPosisi diluar jangkauan\n";
    }
    else if (posisi == 1)
    {
        cout << "\nBukan posisi tengah\n";
    }
    else
    {
        bantu = head;
        int penghitung = 1;
        while (penghitung != posisi)
        {
            penghitung++;
            bantu = bantu->next;
        }
        bantu->ITTP.nama = data.nama;
        bantu->ITTP.nim = data.nim;
    }
}
void tampil()
{
    node *bantu = head;
    cout << "Nama "
         << " Nim\n";
    while (bantu != NULL)
    {
        cout << bantu->ITTP.nama << " " << bantu->ITTP.nim << endl;
        bantu = bantu->next;
    }
}
void hapusDepan()
{
    string dataBefore = head->ITTP.nama;
    hapus = head;
    if (head != tail)
    {
        head = head->next;
        delete hapus;
    }
    else
    {
        head = tail = NULL;
    }
    cout << "Data " << dataBefore << " berhasil dihapus\n";
}
void hapusBelakang()
{
    string dataBefore = head->ITTP.nama;
    if (head != tail)
    {
        hapus = tail;
        bantu = head;
        while (bantu->next != tail)
        {
            bantu = bantu->next;
        }
        tail = bantu;
        tail->next = NULL;
        delete hapus;
    }
    else
    {
        head = tail = NULL;
    }
    cout << "Data " << dataBefore << " berhasil dihapus\n";
}
void hapusTengah()
{
    tampil();
    cout << endl;
    if (isEmpty() == false)
    {
    back:
        int posisi;
        cout << "Masukkan Posisi yang dihapus : ";
        cin >> posisi;
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "\nPosisi di luar jangkauan!\n";
            cout << "Masukkan posisi baru\n";
            goto back;
        }
        else if (posisi == 1 || posisi == hitungList())
        {
            cout << "\nBukan Posisi tengah\n";
            cout << "Masukkan posisi baru\n";
            goto back;
        }
        else
        {
            bantu = head;
            int penghitung = 1;
            while (penghitung <= posisi)
            {
                if (penghitung == posisi - 1)
                {
                    before = bantu;
                }
                if (penghitung == posisi)
                {
                    hapus = bantu;
                }
                bantu = bantu->next;
                penghitung++;
            }
            string dataBefore = hapus->ITTP.nama;
            before->next = bantu;
            delete hapus;
            cout << "\nData " << dataBefore << " berhasil dihapus!\n";
        }
    }
    else
    {
        cout << "\n!!! List Data Kosong !!!\n";
    }
}
void hapusList()
{
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        delete hapus;
        bantu = bantu->next;
    }
    init();
    cout << "\nsemua data berhasil dihapus\n";
}
int main()
{
    init();
    mahasiswa ITTP;
back:
    int operasi, posisi;
    cout << " PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
    cout << " == == == == == == == == == == == == == == == == == == == == == =\n\n " << endl;
    cout << "1. Tambah Depan" << endl;
    cout << "2. Tambah Belakang" << endl;
    cout << "3. Tambah Tengah" << endl;
    cout << "4. Ubah Depan" << endl;
    cout << "5. Ubah Belakang" << endl;
    cout << "6. Ubah Tengah" << endl;
    cout << "7. Hapus depan" << endl;
    cout << "8. Hapus belakang" << endl;
    cout << "9. Hapus Teangah" << endl;
    cout << "10.Hapus list" << endl;
    cout << "11.Tampilkan" << endl;
    cout << "0. Exit" << endl;
    cout << "\nPilih Operasi :> ";
    cin >> operasi;
    switch (operasi)
    {
    case 1:
        cout << "tambah depan\n";
        insertDepan(Pendataan());
        cout << endl;
        goto back;
        break;
    case 2:
        cout << "tambah belakang\n";
        insertBelakang(Pendataan());
        cout << endl;
        goto back;
        break;
    case 3:
        cout << "tambah tengah\n";
        cout << "nama : ";
        cin >> ITTP.nama;
        cout << "NIM : ";
        cin >> ITTP.nim;
        cout << "Posisi: ";
        cin >> posisi;
        insertTengah(ITTP, posisi);
        cout << endl;
        goto back;
        break;
    case 4:
        cout << "ubah depan\n";
        ubahDepan(Pendataan());
        cout << endl;
        goto back;
        break;
    case 5:
        cout << "ubah belakang\n";
        ubahBelakang(Pendataan());
        cout << endl;
        goto back;
        break;
    case 6:
        cout << "ubah tengah\n";
        ubahTengah(Pendataan());
        cout << endl;
        goto back;
        break;
    case 7:
        cout << "hapus depan\n";
        hapusDepan();
        cout << endl;
        goto back;
        break;
    case 8:
        cout << "hapus belakang\n";
        hapusBelakang();
        cout << endl;
        goto back;
        break;
    case 9:
        cout << "hapus tengah\n";
        hapusTengah();
        cout << endl;
        goto back;
        break;
    case 10:
        cout << "hapus list\n";
        hapusList();
        cout << endl;
        goto back;
        break;
    case 11:
        tampil();
        cout << endl;
        goto back;
        break;
    case 0:
        cout << "\nEXIT PROGRAM\n";
        break;
    default:
        cout << "\nSalah input operasi\n";
        cout << endl;
        goto back;
        break;
    }
    return 0;
}
