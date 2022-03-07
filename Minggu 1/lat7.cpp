#include <iostream>
using namespace std;

struct karya{
    long isbn;
    string jdl, pt, kota;
    int hal;
};

int main()
{
    int ISBN;
    karya buku[2];

    for (int i = 0; i < 2; i++)
    {
    cout << "Data Buku ke-" << i+1;
    cin.ignore();
    cout << "Input Judul Buku       : ";getline(cin,buku[i].jdl);
    cout << "Input nomor ISBN       : ";cin >> buku[i].isbn;
    cin.ignore();
    cout << "Input jumlah halaman   : ";cin >> buku[i].hal;
    cin.ignore();
    cout << "Input nama Penerbit    : ";getline(cin,buku[i].pt);
    cout << "Input Kota             : ";getline (cin,buku[i].kota);
    cout << endl;
    }

    cout << "Input ISBN buku : "; cin >> ISBN;
    cout << endl;
    cout << "\t===============================================" << endl;
    cout << "\t                    DATA BUKU" << endl;
    cout << "\t===============================================" << endl;
    for (int i = 0; i < 2; i++)
    {
        if (buku[i].isbn == ISBN)
        {
        cout << "ISBN           : " << buku[i].isbn << endl;
        cout << "Judul Buku     : " << buku[i].jdl << endl;
        cout << "Jumlah Hal     : " << buku[i].hal << endl;
        cout << "Nama Penerbit  : " << buku[i].pt << endl;
        cout << "Kota           : " << buku[i].kota << endl;
        cout << endl;
        }
        
    }
    
    
    return 0;
}
