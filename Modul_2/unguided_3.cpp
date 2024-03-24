#include <iostream>
using namespace std;
int min,max;
    double rata2,jumlah;
    int nilai[10];

int main (){

    int min,max;
    double rata2,jumlah;
    int nilai[10];
    cout<<"Inputkan 10 Nilai Array\n";
    for (int i = 0; i < 10; i++)
    {
        cout<<"nilai ke "<<i+1<<" : ";
        cin>>nilai[i];
    }
    cout<<endl;
    cout<<"Nilai Array: ";
    for (int i = 0; i < 10; i++)
    {
        cout<<nilai[i];
    }
    cout<<endl;
    max=nilai[0];
    for (int i = 0; i < 10; i++)
    {
        if (max < nilai[i])
        {
            max=nilai[i];
        }
        
    }
    cout<<"Nilai Maksimum: "<<max<<endl;
    min=nilai[0];
    for (int i = 0; i < 10; i++)
    {
        if (min>nilai[i])
        {
            min=nilai[i];
        }
        
    }
    cout<<"Nilai Minimum: "<<min<<endl;
    
    for (int i = 0; i < 10; i++)
    {
        jumlah += nilai[i];
        rata2= jumlah/10;
        
    }
    cout<<"Rata-rata: "<<rata2;
return 0;
} 
