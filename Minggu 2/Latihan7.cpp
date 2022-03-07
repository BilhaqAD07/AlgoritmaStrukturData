#include <iostream>
using namespace std;

int Aneh(int z){
    if(z > 0){
        if(z % 2 == 0){
            return z - Aneh(z-3) * Aneh(z-2);
    } else {
        return z + Aneh(z-2) * Aneh(z-1);
    }
        } else {
            return z;
        }
}


int main()
{
    cout << Aneh(6) << endl;
}
