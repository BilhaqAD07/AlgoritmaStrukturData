#include <iostream>
using namespace std;

// DISCLAIMER : Untuk Program kali ini tidak menggunakan sistem list melainkan record biasa karena otak sang pembuat tidak mencapai sejago itu, terimakasih

// Kedua baris dibawah ini merupakan deklarasi variabel global yang akan digunakan dalam fungsi"nya
const int maks = 7; 
int top = -1;

struct dataStack{   // Merupakan fungsi struct record untuk deklarasi data stack nantinya
    string nama[maks], asal[maks];
    int umur[maks];
};
dataStack data; // Memperkecil nama variabel

void pushData(string box1, int box2, string box3){ // Fungsi ini berfungsi sebagai pembagian tempat sesuai kategori dengan variabel yang telah di definisikan agar konsep stack terlihat
    if (top > maks)
    {
        cout << "Stack telah Overflow" << endl;
    } else {
        top++;
        data.nama[top] = box1;
        data.umur[top] = box2;
        data.asal[top] = box3;
    }
}

void inputData(int N){  // Fungsi ini berfungsi sebagai input data yang akan dimasukkan ke Fungsi pushData() 
    int umur;
    string asal, nama;

    for (int i = 0; i < N; i++)
    {
        cout << "Nama\t\t: "; cin >> nama;
        cout << "Umur(tahun)\t: "; cin >> umur;
        cin.ignore(256,'\n'); // Code di baris ini berfungsi apabila user menambahkan spasi pada saat diminta meng-input data asal kota ke user dengan menggunakan getline
        cout << "Asal\t\t: "; getline(cin,asal);
        pushData(nama, umur, asal); // Pemanggilan fungsi pushData()
        cout << endl;
    }
}

void popData(string* takenama, int* takeumur, string* takeasal){ // Fungsi ini berfungsi untuk menghapus data stack, apabila data stack kosong maka stack underflow
    if (top < 0)
    {
        cout << "Stack telah Underflow";
    } else  // Apabila kondisi tidak terpenuhi, maka data yg diinputkan akan dipindahkan ke variabel yang terdapat pada definisi fungsi
        *takenama = data.nama[top];
        *takeumur = data.umur[top];
        *takeasal = data.asal[top];
        top--;
}

void outputData(){ // Fungsi ini berfungsi untuk mengeluarkan output ke layar user
    if (top < 0) // Percabangan ini mengecek apabila data stack ada atau tidak, apabila tidak ada daa maka akan mengeluarkan output empty
    {
        cout << "Stack is empty" << endl;
    } else
    {
        cout << "No\tNama\tUmur\tAsal" << endl;
        int no=1;
        for (int i = top; i >=0 ; i--)
        {
            popData(&data.nama[i], &data.umur[i], &data.asal[i]);   // Pemanggilan fungsi popData() apabila ada data yang ingin diambil di input sebelumnya
            cout << no << "     " << data.nama[i] << "\t" << data.umur[i] << " tahun " << data.asal[i] << endl;
            no++;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    inputData(N);
    outputData();
    
    return 0;
}
