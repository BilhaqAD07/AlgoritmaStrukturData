#include <iostream>
using namespace std;
void balik (int *A){
  //disini kita membalik nilainya contoh 21 jadi 12, 13 jadi 31
  if(*A%10==*A){//kalau nilainya kurang dari sepuluh atau hanya satu
    *A=*A*10; // dikali sepuluh karena 1 = 01 dibalik jadi 10
  } else {
    *A = (*A%10) * 10 + *A/10;
  }
}
void tukar(int *A, int *B){
  //fungsi tukar
  int C=*A;
  *A=*B;
  *B=C;
}
void Urut (int A[], int n){
  //using bubble sort
  for(int i=1;i<n;i++){
    for(int j=n-1;j>=i;j--){
      if(A[j]<A[j-1]){
        tukar(&A[j],&A[j-1]);
      }
    }
  }
  //for(int i=0;i<n;i++) cout<<A[i]<<' ';
  //cout<<endl;

}
int main (){
  int N;
  cin >> N;
  int X[N], i=0;
  while (i < N){
    cin >> X[i];
    balik(&X[i]);
   i++;
  }
  //for(int i=0;i<N;i++) cout<<X[i]<<' ';
  //cout<<endl;
  Urut(X, N);
  //for(int i=0;i<N;i++) cout<<X[i]<<' ';
  //cout<<endl;
  i=0;
  while (i < N){
    balik(&X[i]);
    cout << X[i] <<endl;
    i++;
  }
  return 0;
}
// inputan
//10
//1 11 12 2 13 23 31 62 71 81