#include <iostream>
using namespace std;

long int deret2(int x){
    if(x==1) return 2;
    else deret2(x-1); cout << 2*x-2 << "+";
        return x*2;
}

int main()
{
    int n;
    cout << "Masukkan Angka : ";
    cin >> n;
    cout << deret2(n) << endl;
    return 0;
}
