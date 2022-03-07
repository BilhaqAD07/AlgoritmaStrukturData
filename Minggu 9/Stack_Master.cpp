#include <iostream>
using namespace std;

int maks = 6;
int top = 0;
string arrayBuku[6];

bool isFull(){
    if (top == maks)
    {
        return true;
    } else {
        return false;   
    }
}

bool isEmpty(){
    if (top == 0)
    {
        return true;
    } else {
        return false;
    }
}

void pushArray(string data){
    if (top >= maks)
    {
        cout << "Maaf data penuh" << endl;
    } else
        arrayBuku[top] = data;
        top++; 
}

void popArray(){
    if (isEmpty())
    {
        cout << "Maaf data kosong" << endl;
    } else 
        arrayBuku[top-1] = "";
        top--;
}

void cetakData(){
    cout << "Data Stack Array Buku : " << endl;
    for (int i = maks-1; i >=0 ; i--)
    {
        if (arrayBuku[i] != "")
        {
            cout << "Data ke-" << i << " : " << arrayBuku[i] << endl;
        }
    }
    cout << endl << endl;
}

int countArray(){
    if (isEmpty())
    {
        cout << "Maaf data kosong" << endl;
    } return top;
    
}

void peakArray(int posisi){
    if (isEmpty())
    {
        cout << "Maaf data kosong" << endl;
    } else { 
        int index = top;
        for (int i = 0; i < posisi; i++)
        {
            index--;
        }
        cout << "Data pada posisi ke-" << posisi << " adalah : " << arrayBuku[index] << endl;
    }
}
int main()
{
    pushArray("Logika Perograman Python");
    pushArray("Machine Learning");
    pushArray("Artificial Intelligence");
    pushArray("Aplikasi Arduino dan Sensor");
    cetakData();

    cout << "Tampilkan jumlah data : " << countArray() << endl;

    popArray();
    cetakData();

    pushArray("hehe");
    pushArray("huhu");
    pushArray("hihi");
    pushArray("hoho");

    cetakData();
    peakArray(4);

    destroyArray();
    cetakData();

    cout << "Tampilkan jumlah data : " << countArray() << endl;
    
    cout << "Apakah stack full? : " << isFull() << endl;
    cout << "Apakah stack empty? : "<< isEmpty() << endl; 
    system("pause");
    return 0;
}
