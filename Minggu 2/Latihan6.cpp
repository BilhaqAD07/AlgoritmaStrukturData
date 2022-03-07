#include<iostream>
#include<math.h>
using namespace std;


    int start=0;
float hitung_keliling(float x,float y){
	
	float hasil;
	
	
	if(start<y){
	start++;
	
	hasil=x+hitung_keliling (x*(sqrt(2)/2),y);
	}
	else{
		return hasil;
	}
}

int main(){
	//Terdapat 4 bangun persegi dan 3 belah ketupat
	//Perulangan pola yang terbentuk tiap bangun adalah n*4+...+(n*sqr(2)/2)*4
	//n*4+...+(n*sqr(2)/2)4 = 4(n+...+(n*sqr(2)/2))
	
	int jumlah_bangun=7;
	int keliling_awal=100;

	cout<<"Total keliling seluruh bangun adalah ="<<hitung_keliling(keliling_awal,jumlah_bangun)*4<<"cm^2";
	
}