#include <iostream>
using namespace std;

long int isGanjil(int input){
    if (input == 0){
        cout << "false"; return 0;
    }    
    else if (input == 1){
        cout << "true"; return 0;
    } else return isGanjil(input-2); 
}

int main()
{
    int input;
    cout << "Masukkan angka : ";
    cin >> input;

    isGanjil(input);

    cout << endl;
    return 0;
}
