#include<iostream>
using namespace std;
int maks = 10;
int top = 0;
string arrayBuku[10];

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
        cout << "Stack Overflow" << endl;
    } else
        arrayBuku[top] = data;
        top++; 
}
void pop(){
    if (isEmpty())
    {
        cout << "Stack underflow" << endl;
    } else 
        arrayBuku[top-1] = "";
        top--;
}
int countArray(){
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
    } return top;
    
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
int main (){
	pushArray("Data Stack pada Array :");
    pushArray("Data : Buku Penataan Perkotaan");
    pushArray("Data : Buku Fisika Kebumian");
    pushArray("Data : Buku Kimia Organik ");
    pushArray("Data : Buku Biologi Tumbuhan ");
    pushArray("Data : Buku Matematika Dasar ");
    cetakData();
    
    cout<<endl<<endl;
    
    pushArray("Data Stack pada Array :");
    pushArray("Data : Buku Algoritma dan Struktur Data");
    pushArray("Data : Buku Basis data");
    pushArray("Data : Buku Penataan Perkotaan ");
    pushArray("Data : Buku Fisika Kebumian ");
    pushArray("Data : Buku Kimia Organik ");
    pushArray("Data : Buku Biologi Tumbuhan ");
    pushArray("Data : Buku Matematika Dasar ");
    cetakData();
    
    cout<<endl<<endl;
    
    pushArray("Data : Buku Fisika Kebumian ");
    pushArray("Data : Buku Kimia Organik ");
    pushArray("Data : Buku Biologi Tumbuhan ");
    pushArray("Data : Buku Matematika Dasar ");
    cetakData();
    
    cout << "Apakah stack sudah habis? : "<< isEmpty() << endl; 
    
    
}