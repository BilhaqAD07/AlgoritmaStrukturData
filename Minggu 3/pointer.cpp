#include <iostream>
using namespace std;

void tukar(int *x, int *y){
    int tmp;
    tmp=*x;
    *x=*y;
    *y=tmp;
}
int main()
{
    int bil_1, bil_2;

    cout << "Input bilangan 1 : "; cin >> bil_1;
    cout << "Input bilangan 2 : "; cin >> bil_2;
    
    tukar(&bil_1, &bil_2);
    cout << "Nilai setelah ditukar" << endl;
    cout<<bil_1 << endl;
    cout<<bil_2 << endl;
    
    return 0;
}
