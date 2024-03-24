#include <iostream>
using namespace std;

int nilai[10];
int main (){

    cout<<"Inputkan Nilai Array\n";
    for (int i = 0; i < 10; i++)
    {
        cout<<"nilai ke "<<i+1<<" : ";
        cin>>nilai[i];
    }
    cout<<"Data Array: ";
    for (int i = 0; i < 10; i++)
    {
        cout<<nilai[i];
    }
    cout<<endl;

    cout<<"Nomor Genap: ";
    for (int i = 0; i < 10; i++)
    {
        if (nilai[i] % 2 == 0)
        {
            cout<<nilai[i]<<",";
        }
        
    }
    cout<<endl;
    cout<<"Nomor Ganjil: ";
    for (int i = 0; i < 10; i++)
    {
        if (nilai[i] % 2 != 0)
        {
            cout<<nilai[i]<<",";
        }
        
    }
return 0;
}
