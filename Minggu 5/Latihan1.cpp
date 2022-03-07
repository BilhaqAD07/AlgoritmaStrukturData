#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct TElmtList *address;
typedef struct TElmtList {
	infotype info;
	address next;
} ElmtList;

typedef struct List {
	address first;
};

void CreateEmpty(List *L) {
    (*L).first = NULL;
}

bool IsEmpty(List L) {
    return ((L).first == NULL);
}

address Allocation(infotype x) {
    address NewElmt;
    NewElmt = (ElmtList*) malloc (sizeof(ElmtList));

    NewElmt->info = x;
    NewElmt->next = NULL;

    return NewElmt;
}

void Deallocation(address hapus) {
    free(hapus);
}

void InsertFirst(List *L, infotype x) {
    address NewElmt;
    NewElmt = Allocation(x);

    if (NewElmt != NULL) {
        NewElmt->next = (*L).first;
        (*L).first = NewElmt;
    }
}

void InsertAfter(address *PredElmt, infotype x) {
    address NewElmt;
    NewElmt = Allocation(x);

    if (NewElmt != NULL) {
        NewElmt->next = (*PredElmt)->next;
        (*PredElmt)->next = NewElmt;
        
    }
}

void InsertLast(List *L, infotype x) {
    if (IsEmpty(*L)) {
        InsertFirst(&(*L), x);
    } else {
        address temp;
        temp = (*L).first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        InsertAfter(&temp, x);
    }
}

void DeleteFirst(List *L, infotype *hapus) {
    if (!IsEmpty(*L)) {
        address temp;
        temp = (*L).first;
        *hapus = temp->info;
        (*L).first = (*L).first->next;
        temp->next = NULL;
        Deallocation(temp);
    }
}

void DeleteAfter(address pred, infotype *hapus) {
    if (pred->next != NULL) {
        address temp;
        temp = pred->next;
        *hapus = temp->info;
        pred->next = temp->next;
        temp->next = NULL;
        Deallocation(temp);
    }
}

void DeleteLast(List *L, infotype *hapus) {
    if (!IsEmpty(*L)) {
        address temp, predTemp;
        predTemp = NULL;
        temp = (*L).first;
        while (temp->next != NULL) {
            predTemp = temp;
            temp = temp->next;
        }

        if (temp == (*L).first) {
            DeleteFirst(&(*L), &(*hapus));
        } else {
            DeleteAfter(predTemp, &(*hapus));
        }
    }
}

void insert_number(List *L, infotype angka){

        // Buatlah fungsi sesuai dengan Tugas Mandiri 1, soal 2
    if (IsEmpty(*L)) {
        InsertFirst(&(*L), angka);
    } else {
        address temp,before;
        temp = (*L).first;
        before = temp;
        if(angka < temp->info ){
            InsertFirst(&(*L), angka);
        }else if(temp->next != NULL ){
            while (temp->info <= angka && temp->next != NULL) {
                before = temp;
                temp = temp->next;
            
            }
            if(before->next != NULL && temp->info > angka){
                InsertAfter(&before, angka);
            }else
                InsertLast(&(*L), angka); 
        }else{
            InsertLast(&(*L), angka);
        }
    }
    
    

}

int main(){
    List data;
    int a;
    bool exit=true;
    
    CreateEmpty(&data); 
    // Panggil fungsi-fungsi insert
    while(exit){
        
        cin>>a;
        insert_number(&data, a);
        cout<<"Exit? 1/0 = ";
        cin>>exit;
    }
    cout<<endl;
    
    
    
    // Print setelah insert
    address temp = data.first;
    while (temp != NULL) {
        cout << temp->info << endl;
        temp = temp->next;
    }

    cout << endl;
    // // Panggil fungsi-fungsi delete
    // int b = 6;
    // DeleteAfter(data.first, &b);
    // // Print setelah delete
    // address tempd = data.first;
    // while (tempd != NULL) {
    //     cout << tempd->info << endl;
    //     tempd = tempd->next;
    // }

    return 0;
}