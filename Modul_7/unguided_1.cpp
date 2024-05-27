#include <iostream>
using namespace std;
struct Node
{
    string namaMahasiswa;
    string nim;
    Node *next;
};
class Queue
{
private:
    Node *front;
    Node *back;

public:
    Queue()
    {
        front = nullptr;
        back = nullptr;
    }
    bool isEmpty()
    {
        return (front == nullptr);
    }
    void enqueue(string namaMahasiswa, string nim)
    {
        Node *newNode = new Node{namaMahasiswa, nim, nullptr};
        if (isEmpty())
        {
            front = newNode;
            back = newNode;
        }
        else
        {
            back->next = newNode;
            back = newNode;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Antrian kosong" << endl;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            if (front == nullptr)
            {
                back = nullptr;
            }
            delete temp;
            cout << "Antrian Berhasil Dihapus" << endl;
        }
    }
    void viewQueue()
    {
        if (isEmpty())
        {
            cout << "Antrian kosong." << endl;
        }
        else
        {
            cout << "Data antrian mahasiswa:" << endl;
            Node *current = front;
            int index = 1;
            while (current != nullptr)
            {
                cout << index << ". Nama: " << current->namaMahasiswa << ", NIM: " << current -> nim << endl;
                current = current->next;
                index++;
            }
        }
    }
    void clearQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
    int countQueue()
    {
        int count = 0;
        Node *current = front;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }
};
void displayMenu()
{
    cout << "\nMenu Antrian Teller:" << endl;
    cout << "1. Tambah Antrian" << endl;
    cout << "2. Hapus Antrian" << endl;
    cout << "3. Tampilkan Antrian" << endl;
    cout << "4. Bersihkan Antrian" << endl;
    cout << "5. Hitung Antrian" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilih operasi: ";
}
int main()
{
    Queue q;
    int choice;
    string namaMahasiswa, nim;
    do
    {
        displayMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Masukkan Nama Mahasiswa: ";
            cin.ignore(); // Mengabaikan newline yang tersisa di input buffer
            getline(cin, namaMahasiswa);
            cout << "Masukkan NIM: ";
            cin >> nim;
            q.enqueue(namaMahasiswa, nim);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.viewQueue();
            break;
        case 4:
            q.clearQueue();
            break;
        case 5:
            cout << "Jumlah antrian = " << q.countQueue() << endl;
            break;
        case 6:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 6);
    return 0;
}