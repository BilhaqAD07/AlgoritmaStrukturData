#include <iostream>
using namespace std;

struct DataUser     // Fungsi struct record sebagai penyimpan data user antrian pasien RS
{
    int Nkp;
    string namapasien;

    DataUser *next, *prev;
};

struct list         // Fungsi struct ini sebagai tempat untuk menentukan head dan tail dari list
{
    DataUser *head, *tail;
};

DataUser *newnode, *cur, *pred1, *pred2;

void create (list *l){   // Fungsi ini berfungsi dalam membuat list apabila head/tail adalah NULL
    (*l).head = NULL;
    (*l).tail = NULL;
}

bool check (list l){    // Fungsi berikut berfungsi dalam mengecek apakah list tersebut NULL atau tidak
    return (l.head == NULL && l.tail == NULL);
}

void addfirst(list *l, int nomor, string nama){ // Fungsi ini digunakan untuk menambah isi yang di inputkan user dengan menggeser list ke next apabila list kosong, sedangkan apabila list kosong maka akan mulai kembali dari head
    newnode = new DataUser();

    newnode->Nkp = nomor;
    newnode->namapasien = nama;

    if (check (*l)){
        (*l).head = newnode;
        (*l).tail = (*l).head;
    } else {
        newnode->next = (*l).head;
        (*l).head->prev = newnode;
        (*l).head = newnode;
    }
}

void print(list *l){    // Fungsi berikut berfungsi dalam menampilkan output hasil input ke layar
    cur = (*l).head;
    int step = 1;
    while (cur!= NULL){
        cout << step << " NKP : " << cur->Nkp << '\t' << cur->namapasien<< endl;
        cur= cur->next;
        step ++;
    }
}
void swap (DataUser *data1, DataUser *data2){ // Fungsi berikut digunakan untuk menukar isi dari variabel string dan int menggunakan metode pointer
    int tempNkp = data1->Nkp;
    data1->Nkp = data2->Nkp;
    data2->Nkp = tempNkp;

    string tempnama = data1->namapasien;
    data1->namapasien = data2->namapasien;
    data2->namapasien = tempnama;

}
void sorting(list *l){  // Fungsi sorting disini berfungsi untuk mengurutkan antrian pasien RS, untuk metodenya sendiri menggunakan Bubble Sort dengan perulangan do-while karena hal tersebut yang mudah dipahami
    if (!check (*l)){
        pred2 = NULL;
        int swaped;

        do{
            swaped = 0;
            pred1 = (*l).head;
            while (pred1->next != pred2){
                if (pred1->Nkp > pred1->next->Nkp){
                    swap (pred1, pred1->next);
                    // swap(pred1->Nkp, pred1->next->Nkp);
                    // swap(pred1->namapasien, pred1->next->namapasien);
                    swaped = 1;
                }
                pred1 = pred1->next;
            }
            pred2 = pred1;
        }while (swaped);
    } else{
        return;
    }
}


int main(){
    // Di bawah ini merupakan deklarasi variabel untuk input user
    list daftar;
    int NKP;
    int step= 1;
    string nama;

    create(&daftar); //  Memanggil fungsi membuat list
    cout << "Data ke-" << step << " : "<< endl;
    cout << "NKP\t: " ; cin >> NKP;
    while(NKP != -999){         // Disini ditambahkan kondisi apabila isi NKP == -999, maka program akan mulai mengeluarkan output list
        cout << "Nama\t: "; cin >> nama;
        addfirst(&daftar, NKP, nama);
        step++;
        cout << "Data ke-" << step << " : "<< endl;
        cout << "NKP\t: " ; cin >> NKP;
    }
    
    cout << "\n";
    print(&daftar);

    cout << "\n";

    sorting(&daftar);
    print(&daftar);
}