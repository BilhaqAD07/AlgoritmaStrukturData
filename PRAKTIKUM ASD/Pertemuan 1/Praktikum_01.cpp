#include <iostream>
using namespace std;
int cari(int arr[], int left, int right, int num) { // Deklarasi fungsi "cari" dengan 4 parameter variabel
   if (left <= right) { // Apabila left kurang dari sama dengan right maka akan menginilisasi percabangan 
      int mid = (left + right)/2; // kondisi dimana untuk mencari nilai tengah dari suatu array
      if (arr[mid] == num)  
         return mid ;       // Apabila nilai tengah array sama dengan angka yang dicari maka akan return mid
      if (arr[mid] > num)  
         return cari(arr, left, mid-1, num);  // Apabila nilai tengah lebih dari angka yang dicari makan nilai tengah array dikurangi 1          
      if (arr[mid] < num)
         return cari(arr, mid+1, right, num); // Apabila nilai tengah kurang dari angka yang dicari maka nilai tengah array ditambah 1
   } 
   return -1; // Kondisi dimana semua kondisi percabangan tidak terpenuhi
} 

int main(){
int arr[] = { 2, 3, 4, 10, 40 };
int x = 10; // x adalah bilangan yg dicari (target)
// n adalah panjang dari array
int n = sizeof(arr) / sizeof(arr[0]);
int result = cari(arr, 0, n-1, x);
(result == -1)  ? cout << x << " tidak ada di array"
                : cout << x << " berada pada index ke-" << result;

return 0;
}