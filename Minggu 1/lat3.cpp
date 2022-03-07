#include <iostream>
using namespace std;

int main()
{
    int input;

    cout << "Jumlah orang : "; cin >> input; 
    string nama[input];
    float nikim[input],nimtk[input],nifis[input];
    cout << endl;
    for (int i = 0; i < input; i++)
    {
        cout << "Data ke-" << i+1 << endl;
        cout << "Masukkan Nama  : "; cin >> nama[i];
        cout << "Nilai Kimia    : "; cin >> nikim[i];
        cout << "Nilai Fisika   : "; cin >> nifis[i];
        cout << "Nilai MTK      : "; cin >> nimtk[i];
       
        cout << endl;
    }
    
    cout << "===========================================" << endl << endl;

    for (int i = 0; i < input; i++)
    {
        cout << "Data Mahasiswa ke-" << i+1 << endl;
        cout << "Nama Mahasiswa : " << nama[i] << endl;
        cout << "Nilai Kimia    : " << nikim[i] << endl;
        cout << "Nilai Fisika   : " << nifis[i] << endl;
        cout << "Nilai MTK      : " << nimtk[i] << endl;
        cout << endl;
    }
    
    
    return 0;
}
