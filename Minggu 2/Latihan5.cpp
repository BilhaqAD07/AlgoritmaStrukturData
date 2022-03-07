#include <iostream>
using namespace std;

long int LuasBS(int p, int q, int r, int Sisi)
{
    int t = q + r + Sisi;
    if (q==0)
    {
        cout << "sisi " << Sisi <<" -> luas = " << Sisi << endl;
    } else
    {
        cout << "sisi " << Sisi << " -> luas = " << r << " + " << q+Sisi << " = " << t << endl;
    }
    if (Sisi==p)
    {
        return 0;
    } else
    {
        return LuasBS(p, q+1, t, Sisi+1);
    }
}

int main()
{
    int input;
    cout << "Masukkan Angka : "; 
    cin >> input;
    LuasBS(input,0,0,1);

    return 0;
}