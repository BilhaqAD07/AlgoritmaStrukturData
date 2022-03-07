//queue
#include <iostream>
using namespace std;

int last=-1;
int first=0;
const int maks=10;

struct dataQueue{
    string nama[maks],kota[maks];
    int umur[maks];
};

dataQueue queue;

//mengisi queue
void push(string name, int age, string city) {
    if(last>maks)
        cout<<"Queue Overflow"<<endl;
    else {
        last++;
        queue.nama[last]=name;
        queue.umur[last]=age;
        queue.kota[last]=city;
    }
}

//meminta inputan dan memanggil fungsi push
void input(int n){
    int umur;
    string nama,kota;
    n+=last;
    for(int i=last+1;i<=n;i++){
        cout<<"Nama : ";cin>>nama;
        cout<<"Umur(tahun) : ";cin>>umur;
        cin.ignore();
        cout<<"Asal : "; getline(cin,kota);
        push(nama,umur,kota);
        cout<<endl;
    }
}

//untuk mengeluarkan elemen terdepan dari queue
void served() {
    if(first>last)
        cout<<"Queue Underflow"<<endl;
    else {
        first++;
    }
}

//cetak queue
void display() {
    int i=first;
    if(last>=0) {
        cout<<"No\tNama\tUmur\t\tAsal\n";
        while(i<=last){
            cout<<i+1<<"    "<<queue.nama[i]<<"\t"<<queue.umur[i]<<" tahun\t"<<queue.kota[i]<<endl;
            i++;
        }
    } else
        cout<<"Queue is empty";
}

int main(){
    int n;
    cin>>n;
    input(n);
    display();
    return 0;
}