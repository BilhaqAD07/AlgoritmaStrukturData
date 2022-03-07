#include <iostream>
using namespace std;

float Rparalel(int n){      // Fungsi mencari Hambatan Pararel
    float input, jumlah = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan nilai ke-" << i+1 << " : ";
        cin >> input;
        jumlah += 1.0/input; // Rumus Pararel 1/Hambatan (1/R1+1/R2+1/R3+...Rn)
    }
    jumlah = 1.0/jumlah;    // Dibalikkan agar memudahkan dalam menghitung Kuat Arus
    return jumlah;
}

float Rseri(int n){         // Rumus mencari Hambatan Seri
    float input, jumlah = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan nilai ke-" << i+1 << " : ";
        cin >> input;
        jumlah += input;    // Rumus Seri (R1+R2+R3+...Rn)
    }
    return jumlah;
}

float Baterai(int n){       // Rumus mencari Tegangan
    float input, jumlah = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan nilai ke-" << i+1 << " : ";
        cin >> input;
        jumlah += input;    // Menjumlahkan tegangan di setiap baterai
    }
    return jumlah;
}

float KuatArus(float V, float Rs, float Rp){ // Rumus mencari Kuat Arus
    float I = 0;
    I = V / (Rs+Rp);
    return I;
}

int main()
{
    int Hp, Hs, Batre;
    float V, Rs, Rp, I;
    /*
    V   -> Tegangan
    Rs  -> Hambatan Seri
    Rp  -> Hambatan Pararel
    I   -> Kuat Arus
    n   -> Banyak Input
    */
   cout << "Masukkan jumlah hambatan tersusun paralel   : "; cin >> Hp;
   Rp = Rparalel(Hp);
   cout << "Jumlah nilai hambatan paralel   : " << Rp << endl;
   cout << "Masukkan jumlah hambatan tersusun seri      : "; cin >> Hs;
   Rs = Rseri(Hs);
   cout << "Jumlah nilai hambatan seri      : " << Rs << endl;
   cout << "Masukkan jumlah baterai yang tersusun seri  : "; cin >> Batre;
   V = Baterai(Batre);
   cout << "Jumlah nilai tegangan listrik   : " << V << endl;
   I = KuatArus(V, Rs, Rp);
   cout << "Nilai kuat arus pada Amperemeter adalah : " << I << endl; 

    
    
    return 0;
}
