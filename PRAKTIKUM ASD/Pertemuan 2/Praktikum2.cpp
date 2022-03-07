#include <iostream>
using namespace std;
// DISCLAIMER : Untuk Praktikum minggu ini menggunakan metode matriks ordo 2x2, 
// sehingga baik untuk menginput maupun menmpilkan ke layar maka harus menggunakan perulangan di dalam perulangan
void inputMatriks(float matriks[2][2]){ // Fungsi inputMatriks dengan array 2 dimensi dengan indeks sebesar 2
    int i=0, j=0;
    cout << "Masukkan Nilai : " << endl; 
    for (i = 0; i < 2; i++) for (j = 0; j < 2; j++)
        {
            printf("Matriks [%d][%d] = ", i, j);    // Fungsi printf berfungsi sebagai menampilkan ke layar dengan [%d] untuk mengeluarkan angka desimal dalam array
            cin >> matriks[i][j];
        }
}

void printMatriks(float matriks[2][2]){ // Fungsi printMatriks berfungsi sebagai menampilkan matriks dengan array 2 dimensi dengan indeks sebesar 2
    int i=0, j=0;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            cout << matriks[i][j] << "  ";
        cout << endl;   // endl disini agar output benar-benar terlihat seperti matriks pada umumnya
    }
}

void jumlahInvers(float *matriks, float det){ // Fungsi jumlahInvers berfungsi sebagai tempat penjumlahan matriks hasil dari perhitungan 1/determinan dengan menggunakan pointer
    *matriks /= det;        // Operator disamping sebagai tempat untuk membagi hasil 1/determinan ke anggota matriks dengan rumus 1/determinan(adjoin matriks)
}

void inversMatriks(float matriks[2][2]){ // Fungsi inversMatriks ini berfungsi dalam menentukan adjoin matriks dan determinan matriks agar digunakan untuk mencari Invers matriks
    float det = (matriks[0][0]*matriks[1][1])-(matriks[0][1]*matriks[1][0]);    // variabel det berfungsi sebagai tempat menyimpan determinan
    float temp; // variabel temp berfungsi sebagai tempat sementara menampung nilai matriks yang akan ditukar dalam mencari adjoin matriks
    temp = matriks[0][0];
    matriks[0][0]=matriks[1][1];
    matriks[0][1]=-1*matriks[0][1]; // line ini berarti bahwa matriks indeks ke [0][1] akan dikali dengan -1 
    matriks[1][0]=-1*matriks[1][0]; // line ini berarti bahwa matriks indeks ke [1][0] akan dikali dengan -1 
    matriks[1][1]=temp;

    if (det != 0) // Percabangan ini berfungsi sebagai pengecekan apakah hasil dari determinan tidak sama dengan 0, apabila tidak maka akan menjalankan perulangan
    {
        for (int i = 0; i < 2; i++)  for (int j = 0; j < 2; j++) jumlahInvers(&matriks[i][j], det); // Line ini berarti bahwa matriks hasil adjoin tadi akan dilanjutkan untuk menjalankan fungsi jumlahInvers
        printMatriks(matriks);  // Line ini digunakan untuk menjalankan fungsi printMatriks yang menampilkan output matriks ke layar
    } else cout << "Tidak memenuhi syarat matriks invers" << endl; // Apabila kondisi percabangan tidak terpenuhi maka akan mengeluarkan output seperti ini
}

int main()
{
    float matriks1[2][2];
    inputMatriks(matriks1);

    cout << "Matriks Biasa : " << endl;
    printMatriks(matriks1);
    cout << endl;

    cout << "Matriks Invers : " << endl;
    inversMatriks(matriks1);
    return 0;
}
