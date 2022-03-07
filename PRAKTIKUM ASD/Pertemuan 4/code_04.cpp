// Nama: Fanesa Hadi Pramana
// NIM: 120140189
// Kelas: RD

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct TElmtList *address;
typedef struct TElmtList{
    address prev;
    int NKP;
    string namaPasien;
    address next;
} ElmtList;

struct List {
    address first;
    address last;
};

bool IsEmpty(List L) {
    return (L.first == NULL && L.last == NULL);
}

void CreateEmpty(List *L) {
    (*L).first = NULL;
    (*L).last = NULL;
}

address Allocation(int NKP, string name) {
    address NewElmt;
    NewElmt = (ElmtList*) malloc (sizeof(ElmtList));
    NewElmt->prev = NULL;
    NewElmt->NKP  = NKP;
    NewElmt->namaPasien = name;
    NewElmt->next = NULL;
    return NewElmt;
}

void InsertFirst(List *L, int NKP, string name) {
    address NewElmt;
    NewElmt = Allocation(NKP, name);

    if(NewElmt != NULL) {
        NewElmt->next = (*L).first;
        if(IsEmpty(*L)){
            (*L).last = NewElmt;
        } else{
            ((*L).first)->prev = NewElmt;
        }
        (*L).first = NewElmt;
    }
}

void printDataList(List *L) {
	address temp = (*L).first;
	int urutan = 1;
	while(temp != NULL) {
		cout << urutan << '\t' << temp->NKP << ' ' << temp->namaPasien << '\n';
		temp = temp->next;
		urutan++;
	}
	cout << endl;
}

/**
 * Fungsi untuk melakukan pertukaran data pada
 * element list.
 */
void tukar(address predNode1, address predNode2) {
    int tempNKP = predNode1->NKP;
    string tempNamaPasien = predNode1->namaPasien;
    predNode1->NKP = predNode2->NKP;
    predNode1->namaPasien = predNode2->namaPasien;
    predNode2->NKP = tempNKP;
    predNode2->namaPasien = tempNamaPasien;
}

/**
 * Fungsi untuk melakukan pengurutan data
 * menggunakan algoritma bubble short.
 */
void bubbleShort(List *list) {
    int length = 0;
    address temp1, temp2;

    // Mencari banyaknya data dalam list.
    temp1 = (*list).first;
    while (temp1 != NULL) {
        temp1 = temp1->next;
        length++;
    }

    // Melakukan pengurutan list `bubble short`.
    temp1 = (*list).first;
    temp2 = temp1->next;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if(temp1->NKP > temp2->NKP)
                tukar(temp1, temp2);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp1 = (*list).first;
        temp2 = temp1->next;
    }
}

int main() {
	int NKP;
	string nama;
    List antrian;

    CreateEmpty(&antrian);

    /**
     * Input data antrian pasien.
     */
     cout << "Masukkan daftar NIK dan nama pasien, lalu hentikan masukan dengan -999:\n";
     cout << "NKP: "; cin >> NKP; // Menerima masukan pertama.
     while (NKP != -999) { // Syarat perulangan adalah, inputan NIK tidak bernilai -999.
         cout << "Nama: ";
         cin.ignore();
         getline(cin, nama);

         // Memasukkan data pasien ke list.
         InsertFirst(&antrian, NKP, nama);

         // Menerima masukan berikutnya.
         cout << "NIK: "; cin >> NKP;
    }

    /**
     * Menampilkan data antrian sebelum di urutkan.
     */
    cout << endl << "[DATA ANTRIAN SEBELUM DIURUTKAN]" << endl;
	printDataList(&antrian);

    /**
     * Mengurutkan data dengan algoritma `bubble short`.
     */
    bubbleShort(&antrian);

    /**
     * Menampilkan data antrian setelah di urutkan.
     */
    cout << "[DATA ANTRIAN SETELKEH DIURUTKAN]" << endl;
	printDataList(&antrian);

	return 0;
}
