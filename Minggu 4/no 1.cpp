#include<iostream>
using namespace std;
int tanjakan(int *yy,int zz,int nim){
	int temp=nim%zz;
	if(temp>5){
		*yy=temp+2;
		}	else{
	*yy=temp+1;
	}
	return (yy) zz;
}
int main(){
	int aa,bb,nim,total=0;
	cin>>aa>>nim;
	for(int x=9;x>=1;x--){
		bb=tanjakan(&aa,x,nim);
		total += x+aa-bb;
		cout << "x : " << x << endl;
		cout << "total : " << total << endl;
		cout << "aa : " << aa << endl;
		cout << "bb : " << bb << endl;
	}
	return 0;
}