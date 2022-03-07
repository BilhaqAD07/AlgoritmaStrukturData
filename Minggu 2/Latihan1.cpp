#include <iostream>
using namespace std;

int deret(int x){
    if(x==1)
        return 1;
    else deret(x-1); cout << x-1 << "+";
    return x;
}

int main()
{
    int n;
    cout << "Masukkan Angka : ";
    cin >> n;
    if(n<=0){
        cout << "Tidak dapat dihitung" << endl;
        exit(0);
    }  
    cout << deret(n);
    cout << endl;
    return 0;
}
