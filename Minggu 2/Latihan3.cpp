#include <iostream>
using namespace std;

long int DeretSegitiga(int x,int y, int z){
    int sum=y+z;
    
    if (y == x){
        cout << sum;
        return 0;
    }
     else cout << sum << ", ";
        return DeretSegitiga(x,y+1, sum);
}

int main()
{
    int n;
    cout << "Masukkan Angka : ";
    cin >> n;
    
    DeretSegitiga(n, 1, 0);
    cout << endl;
    
    return 0;
} 
