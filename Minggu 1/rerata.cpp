#include <iostream>
using namespace std;

int main()
{
    float rerata = 0, x, input;
    cout << "Masukkan Jumlah Input : "; cin >> input;
    for (int i = 0; i < input; i++)
    {
        cin >> x;
        rerata += x;
    }
    cout << "Rata - Rata : " << rerata/input << endl;
    
    system("pause");
    return 0;
}
