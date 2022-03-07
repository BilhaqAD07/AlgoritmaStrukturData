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
	First(L)=Nil;
}
address alokasi (infotype X){
//Mengirimkan address hasil alokasi sebuah elemen.Jika alokasi berhasil, maka address tidak Nil danJika alokasi gagal, mengirimkan Nil
	address P = address(malloc(sizeof(address)));
	if(P ==false)
	return Nil;
	Info(P) = X;
	Next(P) = Nil;
	return P;
}
void dealokasi (address *P){
//Melakukan dealokasi/pengembalian address P
	free(*P);
}
void insertFirst (List *L, infotype X){
//Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan nilai X jika alokasi berhasil
	address P = alokasi(X);
	if(P!=Nil){
		Next(P)=First(*L);
		First(*L) = P;
	}
}
void insertAfter (List *L, address P, address Prec){
	Prec=P;
	cout<<Info(P);
	First(*L) = Prec;
}
void insertLast (List *L, infotype X){
//Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir : elemen terakhir yang baru bernilai X jika alokasi berhasil.
	address P = alokasi(X);
	address o = First(*L);
	if(Info(o)==7208832){
		insertFirst(L,X);
	}
	else{
		while(Info(o)!=7208832){
			o = Next(o);
		}
		o=P;
		First(*L) =o;
	}
}
void insertFirst(List *L,address P){
//Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan P hasil Alokasi X.
	Next(P)=alokasi(Info(P));
	First(*L) = P;
}
void insertLast(List *L,address P){
//Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir.elemen terakhir yang baru bernilai P hasil alokasi X.
	if(isListEmpty(*L))
		insertFirst(L,Info(P));
	else{
		address last = P;
		while(last!=Nil){
			cout<<Info(last)<<", ";
			last = Next(last);
		}
		insertAfter(L,P,last);
	}
}

void deleteFirst (List *L, infotype *X){
//Fungsi Menghapus elemen pertama 
	address P = First(*L);
	*X = Info(P);
    if (   X == Nil)
    	cout<<"List NULL"  ;  
    else
        
        Next(P) = Nil;
        dealokasi(&P);
}

void deleteAfter (List *L, address *Pdel, address Prec){
	*Pdel = Next(Prec);
	if(*Pdel!=Nil) {
		 Next(Prec)=Next(Next(Prec));
		 Next(*Pdel)=Nil; 
	}
	dealokasi(Pdel);
}

void deleteLast(List *L, infotype *X){
//Menghapus elemen terakhir
	if(Next(First(*L))==Nil){
		//one element only
		*X = Info(First(*L));
		createList(*L);
	}else{
		address prev = First(*L);
		while(Next(prev)!=Nil ){
			prev = Next(prev);
		}
		address last =prev;
		*X = Info(last);
		dealokasi(&last);
	}
}
void printInfo (List L){
//Semua info yg disimpan pada elemen list diprint dengan format [elemen-1, elemen-2, elemen-3, ...].Jika list kosong, hanya menuliskan "[]"
	if(!isListEmpty(L)){
		address P = First(L);
		while(Info(P) != 7208832){
			cout<<Info(P);
			P = Next(P);
			if(Info(P) != 7208832){
				cout<< "," ;
			}
		}
	}
}
void reverseList (List *L){
//Fungsi membalik isi elemen yang terakhir ke awal 
	address next,curr,prev;
	next = First(*L);
	while(Info(Next(next)) != 7208832){
		curr=next;
	}
	First(*L)=curr;
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
	printInfo(L);//cetak list
}