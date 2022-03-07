#include <iostream>
using namespace std;

int top=-1;
const int maks=10;
struct dataStack{
    string nama[maks],kota[maks];
    int umur[maks];
};

dataStack stack;

//mengisi stack
void push(string val1, int val2, string val3) {
    if(top>maks)
    cout<<"Stack Overflow"<<endl;
    else {
        top++;
        stack.nama[top]=val1;
        stack.umur[top]=val2;
        stack.kota[top]=val3;
    }
}

//meminta inputan
void input(int n){
    int umur;
    string nama,kota;
    for(int i=0;i<n;i++){
        cout<<"Nama : ";cin>>nama;
        cout<<"Umur(tahun) : ";cin>>umur;
        cin.ignore();
        cout<<"Asal : "; getline(cin,kota);
        push(nama,umur,kota);
        cout<<endl;
    }
}


//untuk mengeluarkan sebuah  elemen dari stack
void pop() {
    if(top<0)
    cout<<"Stack Underflow"<<endl;
    else {
        top--;
    }
}

//cetak stack
void display() {
    if(top>=0) {
        cout<<"No\tNama\tUmur\tAsal\n";
        int urut=1;
        for(int i=top; i>=0; i--){
            cout<<urut<<"   "<<stack.nama[i]<<"\t"<<stack.umur[i]<<" tahun "<<stack.kota[i]<<endl;
            urut++;
        }
    } else
    cout<<"Stack is empty";
}

int main(){
    int n;
    cin>>n;
    input(n);
    display();
    return 0;
}