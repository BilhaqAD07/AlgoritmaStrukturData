#include <iostream>
using namespace std;

struct userData{	// Berikut merupakan record dari fungsi userData yang berfungsi untuk menyimpan data dengan type data yang sama
    string Nama, Nim, Hp;
    userData *next;
};

struct list{		// Fungsi record ini berfungsi dalam mengatur head, tail, current, node, delete, dan before saat di dalam codingan
    userData *head;
};
userData *tail, *curr, *newNode, *del, *before;

void create(list *l){	
    (*l).head = NULL;
}

void insertFirst(list *l, string nama, string nim, string hp){ // Fungsi input ketika head masih kosong atau ingin mengiputkan data di awal list
    newNode = new userData();
    newNode->Nama = nama;
    newNode->Nim = nim;
    newNode->Hp = hp;
    newNode->next = (*l).head;
    (*l).head = newNode;
}

void insertLast(list *l, string nama, string nim, string hp){ // Fungsi input ketika head sudah terisi, disini program akan menginput data di list selanjutnya
    newNode = new userData();
    newNode->Nama = nama;
    newNode->Nim = nim;
    newNode->Hp = hp;

    tail = (*l).head;
    while (tail->next != NULL){
        //step
        tail = tail->next;
    }
    newNode->next = tail->next;
    tail->next = newNode;

}

void concat(list *l, list *j){ // Fungsi ini berfungsi dalam penggabungan list antara antrian awal dan antrian akhir
    tail = (*l).head;
    while(tail->next != NULL){
        //step
        tail = tail->next;
    }
    tail->next = (*j).head;
}

void deletefirst(list *l){ // Fungsi untuk menghapus data list yang masih terletak di awal list
    del = (*l).head;
    (*l).head = (*l).head->next;
    delete del;
}

void deletelist(list *l, string delnim){ // Fungsi yang berfungsi untuk menghapus data list
    if ((*l).head->Nim == delnim){ // Percabangan disamping sebagai pengecek apabila data NIM pertama == delnim
        deletefirst(&(*l));
    } else{
        curr = (*l).head;
        while(curr->Nim != delnim){
            //step
            before = curr;
            curr = curr->next;
            if (curr->next == NULL){
                cout << "Data NIM tidak di temukan!" << endl;
                break;
            }
        }
        del = curr;
        before->next = curr->next;
        cout << "Data NIM : " << del->Nim << " tidak mengikuti vaksinasi" << endl;
        delete del;
    }
}

void printList(list *l){ // Fungsi untuk menge-print list
    curr = (*l).head;
    int no = 1;
    while (curr != NULL){
        cout << "Nomor antrian vaksinisasi : " << no <<endl;
        cout << "Nama   : " << curr->Nama << endl;
        cout << "NIM    : " << curr->Nim << endl;
        cout << "No.HP\t: " << curr->Hp << endl;
        cout << endl;
        //step
        no++;
        curr = curr->next;
    }
}

int main(){
    list data1, data2; // Deklarasi list dari record
    create(&data1);  // Memanggil fungsi pembuatan list
    create(&data2);
    
    int pilih, n=0, m=0;
    char ulang, lagi;

    cout << "DAFTAR VAKSINASI : " << endl;
    cout << "1. Daftar Antrian Normal" << endl;
    cout << "2. Daftar Antrian Akhir" << endl;
    cout << endl;

    do {	// Memasukkan data ke fungsi linked-list
        string nama, nim, hp;
        cout<<"Jenis Pendaftaran(1/2) : " ; cin >> pilih;
        cin.ignore(256, '\n');
        cout << "Input Nama	: "; getline(cin, nama);
        cout << "Input NIM	: "; cin >> nim;
        cout << "Input No.HP	: "; cin >> hp;
        
        // Data antrian normal
        if (pilih == 1){
            if (n != 0){
                insertLast (&data1, nama, nim, hp);	// Apabila n!=0 maka akan menjalankan fungsi insertLast yang menambahkan data di akhir list
            }else{
                insertFirst(&data1, nama, nim, hp);	// Apabila sebaliknya maka akan menjalankan fungsi insertFirst yang menambahkan data di awal list
            }
            n++;
            
            // Data antrian akhir
        } else if (pilih == 2){
            if (m != 0){
                insertLast (&data2, nama, nim, hp);
            }else{
                insertFirst(&data2, nama, nim, hp);
            }
            m++;
        }else{
            cout << "\nMaaf pilihan salah, Silakan Coba Lagi.." << endl;
            exit(0);
        }
        
        cout << "Ada pendaftar baru?(Y/N) : "; cin >> ulang;
        cout << endl;
    }while (ulang == 'Y' || ulang == 'y');
    
    cout << endl;
    cout << "DAFTAR ANTRIAN NORMAL" << endl;
    printList(&data1); // Memanggil fungsi printList untuk meng-output-kan di layar data antrian normal

    cout << endl << endl;
    cout << "DAFTAR ANTRIAN AKHIR" << endl;
    printList(&data2);// Memanggil fungsi printList untuk meng-output-kan di layar data antrian akhir
    
    concat(&data1, &data2); // Penggabungan list pada data2 yang akan dimasukkan ke data ke-1 (antrian awal)
    
    do{	// Penghapusan data terhadap list yang sudah digabungkan
        string delnim;
        cout << endl;
        cout << "Input NIM yang tidak ikut vaksinasi :";cin >> delnim; // Fungsi menghapus data dengan menggunakan NIM sebagai acuan
        deletelist(&data1,delnim);
        cout << "Apakah terdapat yang tidak datang lagi?(Y/N) : "; cin >> lagi;
    }while (lagi == 'Y'|| lagi == 'y');
    cout << endl << endl; 
    cout << "DATA PESERTA VAKSINISASI" <<  endl;
    printList(&data1);

return 0;
}
