#include <iostream>
using namespace std;

struct dataUser{ // fungsi untuk deklarasi list/ alamat 
    int info;

    dataUser *next;
};

struct list // fungsi mendeklarasikan fungsi variabellist menggunakan record
{
    dataUser *head;
};
dataUser *tail, *cur, *newNode, *del, *before;

void create(list *l){ // Membuat list
    (*l).head = NULL;
}
// Fungsi input ketika head masih kosong atau ingin mengiputkan data di awal list
void addfirst(list *l, int info){
    newNode = new dataUser();
    newNode->info = info;
    newNode->next = (*l).head;
    (*l).head = newNode;
}

void printList(list *l){ // Fungsi untuk menge-print list
    cur = (*l).head;
    int nomor = 1;
    cout<<"[";
    while (cur != NULL){
        if(cur->next==NULL){
            cout<<cur->info;
        }else{
            cout<<cur->info<<",";
        }
		
        cur = cur->next;
    }
    cout<<"]\n";
}
int main(){
	list L;// Inisialisasi list
	create(&L);// Membuat list
	int jumlah,input;// meng-inisialisas integer
	cout<<"Masukkan Banyak data :";cin>>jumlah;//masukan banyak n
	for (int i =0;i<jumlah;i++){
    cout<<"Angka ke-"<<i+1<<" = ";
		cin>>input;//Input masukan integer
		addfirst(&L,input);// Memasukan kedalam list
	}
	cout<<"Hasil Pembalikan adalah : ";
	printList(&L);// Mencetak list
}