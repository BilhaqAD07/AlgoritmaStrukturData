#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int infotype;
typedef struct tElmtList*address;
typedef struct tElmtList{
	infotype 	info;
	address 	next;
} ElmtList;
typedef struct {
	address		first;
} List;
//SELEKTOR 
#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P) (P)->info
//KONSTANTA
#define Nil NULL
#define Infinity 99999
bool isListEmpty (List L){
	if(First(L)==Nil){
		return true;//Mengirim true jika list kosong
	}
	return false;
}
void createList (List L){
	(L).first=Nil;
}
address alokasi (infotype X){
//Mengirimkan address hasil alokasi sebuah elemen.Jika alokasi berhasil, maka address tidak Nil danJika alokasi gagal, mengirimkan Nil
	address P = address(malloc(sizeof(address)));
	if(P == Nil) return Nil;
	Info(P) = X;
	Next(P) = Nil;
	return P;
}

void insertFirst (List *L, infotype X){
//Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan nilai X jika alokasi berhasil
	address P = alokasi(X);
	if(P!=Nil){
		Next(P)=First(*L);
		First(*L) = P;
	}
}





void printInfo (List *L){
//Semua info yg disimpan pada elemen list diprint dengan format [elemen-1, elemen-2, elemen-3, ...].Jika list kosong, hanya menuliskan "[]"
	if(!isListEmpty(*L)){
		address P = First(*L);
        cout<<"[";
		while(P != Nil){
            cout<<Info(P);
            P = Next(P);
            if(P==Nil){
                cout<<"]";
            }else{
                cout<<",";
            }
            
			
		}
	}
}

int main(){
	List L;//inisialisasi list
	createList(L);//membuat list
	int n,x;// inisialisas integer
	cout<<"Masukkan Banyak data :";cin>>n;//masukan banyak n
	for (int i =0;i<n;i++){
    	cout<<"Angka ke-"<<i+1<<" = ";
		cin>>x;//masukan integer
		insertFirst(&L,x);//masukan kedalam list
	}
	//reverseList(&L);
	cout<<"Hasil Pembalikan adalah : ";
	printInfo(&L);//cetak list
}