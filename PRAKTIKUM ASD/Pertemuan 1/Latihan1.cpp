#include <iostream>
using namespace std;

void Persegi(int x, int y, int z){
  if(y>0){
if(x==0){
  cout << endl;
  Persegi(z,y-1,z);
} else{
  cout << "*";
  Persegi(x-1,y,z);
}
}
}

int main() {
  int p, l;
  cin >> p >> l;
  Persegi(p,l,p);
  return 0;
}