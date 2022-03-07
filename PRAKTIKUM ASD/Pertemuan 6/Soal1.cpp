#include <iostream>
using namespace std;

// DISCLAIMER : Untuk Program kali ini tidak menggunakan sistem list(node) melainkan record biasa karena otak sang pembuat tidak mencapai sejago itu dan mohon maaf apabila program tiddak sesuai dengan apa yang diminta, terimakasih

// Ketiga baris dibawah ini merupakan deklarasi variabel global yang akan digunakan dalam fungsi"nya
const int maks = 7; 
int last = -1;
int first = 0;

struct dataQueue{   // Merupakan fungsi struct record untuk deklarasi data Queue nantinya
    string nama[maks], asal[maks];
    int umur[maks];
};
dataQueue datri; // Memperkecil nama variabel


void pushData(string nama, int umur, string asal){ // Fungsi ini berfungsi sebagai pembagian tempat sesuai kategori dengan variabel yang telah di definisikan agar konsep Queue terlihat
    if (last > maks)
    {
        cout << "Queue telah Overflow\n";
    } else {
        last++;
        datri.nama[last] = nama;
        datri.umur[last] = umur;
        datri.asal[last] = asal;
    }
}

void addData(){  // Fungsi ini berfungsi sebagai input data yang akan dimasukkan ke Fungsi pushData() 
    int umur, N;
    string asal, nama;
    cout << "Input Jumlah Peserta : ";
    cin >> N;
    N += last;
    for (int i = last+1; i <= N; i++)
    {
        cout << "Nama\t\t: "; cin >> nama;
        cout << "Umur(tahun)\t: "; cin >> umur;
        cin.ignore(256,'\n'); // Code di baris ini berfungsi apabila user menambahkan spasi pada saat diminta meng-input data asal kota ke user dengan menggunakan getline
        cout << "Asal\t\t: "; getline(cin,asal);
        pushData(nama, umur, asal); // Pemanggilan fungsi pushData()
        cout << endl;
    }
}

void delData(){ // Fungsi ini berfungsi untuk menghapus data Queue, apabila data Queue kosong maka Queue underflow
    if (first > last)
    {
        cout << "Queue telah Underflow";
    } else { // Apabila kondisi tidak terpenuhi, maka data yg diinputkan akan di hapus karena sudah dilayani
        first++;
    }
}

void outputData(){ // Fungsi ini berfungsi untuk mengeluarkan output ke layar user
    if (last >= 0) // Percabangan ini mengecek apabila data Queue ada atau tidak, apabila tidak ada daa maka akan mengeluarkan output empty
    {
        cout <<"======== DAFTAR NAMA PESERTA ========\n\n";
        cout << "No\tNama\tUmur\tAsal" << endl;
        for (int i = first; i <= last ; i++)
        {
            cout << i+1 <<"     "<< datri.nama[i] << "\t" << datri.umur[i] << " tahun " << datri.asal[i] << endl;
        }
        cout <<"\n====================================\n\n";
    } else {
        cout << "Queue kosong" << endl;
    }
}

void menu(){ // Fungsi ini duganakan sebagai menu yang mempermudah si User yang di dalamnya terdapat percabangan
    int pilih, pilih1;
    cout << "======== MENU ADMINISTRASI ITERA GOT TALENT ========" << endl;
    cout << "=                  1. Tambah Data                  =" << endl;
    cout << "=                  2. Print Data                   =" << endl;
    cout << "=                  3. Sudah Tampil                 =" << endl;
    cout << "=                  0. Selesai                      =" << endl;
    cout << "====================================================" << endl;
    cout << "Pilihan Menu(1/2/3/0) : "; cin >> pilih;
    cout << endl;
    if (pilih == 1) // Percabangan kondisi pertama akan menjalankan fungsi addData()
    {
        addData();
    } else if (pilih == 2)  // Percabangan kondisi kedua akan menjalankan fungsi outputData()
    {
        outputData();
    } else if (pilih == 3)  // Percabangan kondisi ketiga akan menjalankan fungsi delData()
    {
        delData();
    } else if (pilih == 0) // Percabangan kondisi 4 akan mengakhiri program
    {
        cout << "\n======== SELAMAT TINGGAL:) ========" << endl;
        exit(0);
    } else { // Pada kondisi ini terjadi apabila user menginputkan selain input-an yang diminta oleh program
        cout << "Input Salah, Coba lagi!" << endl << endl;
        menu();
    }
    menu();
}

int main()
{
    menu();
    return 0;
}
