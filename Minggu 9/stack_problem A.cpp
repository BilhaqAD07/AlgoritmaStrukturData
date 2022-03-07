#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct TElmtStack *address;
typedef struct TElmtStack{
    infotype info;
    address next;
} ElmtStack;

struct Stack {
    address top;
};

#define Top(S) (S).top
#define InfoTop(S) (S).top->info
#define Next(P) (P)->next
#define Info(P) (P)->info

bool IsEmpty(Stack S) {
    return (Top(S) == NULL);
}

void CreateEmpty(Stack *S) {
    Top(*S) = NULL;
}

void Deallocation(address P) {
    free(P);
}

address Allocation(infotype X) {
    address NewElmt;
    NewElmt = (ElmtStack*) malloc (sizeof(ElmtStack));

    Info(NewElmt) = X;
    Next(NewElmt) = NULL;

    return NewElmt;
}

void Push(Stack *S, infotype X) {
    address NewElmt;
    NewElmt = Allocation(X);

    if (NewElmt != NULL) {
        Next(NewElmt) = Top(*S);
        Top(*S) = NewElmt;
    }
}

void Pop(Stack *S, infotype *X) {
    if (!IsEmpty(*S)) {
        address temp;
        temp = Top(*S);

        *X = Info(temp);
        Top(*S) = Next(temp);
        Next(temp) = NULL;
        Deallocation(temp);
    }
}

struct coba{
    string kalimat;
};

void reverseList (Stack *S){
    /*    I.S. L terdefinisi, boleh kosong
        F.S. Elemen list L dibalik :
        Elemen terakhir menjadi elemen pertama, dan seterusnya.
        Membalik elemen list, tanpa melakukan alokasi/dealokasi.
    */
    address next,curr,prev;
    next = Top(*S);
    curr = next;
    prev = NULL;
    while (curr!= NULL ){
        next = Next(curr);
        Next(curr)=prev;
        prev = curr;
        curr = next;
    }
    Top(*S)= prev;



}

int main(){

    int hapus=0;
    int n;
    cin >> n;

   coba A[n];

   for(int i=0;i<n;i++){
        cin >> A[i].kalimat;
   }

   Stack data;
    CreateEmpty(&data);

    for(int i=0;i<n;i++){
           for(int j=0;j<((A[i].kalimat).length());j++){


               if(A[i].kalimat[j]=='0'){
                   Push(&data,0);
               }else if(A[i].kalimat[j]=='1'){
                   Push(&data,1);
               }else if(A[i].kalimat[j]=='2'){
                   Push(&data,2);
               }else if(A[i].kalimat[j]=='3'){
                   Push(&data,3);
               }else if(A[i].kalimat[j]=='4'){
                   Push(&data,4);
               }else if(A[i].kalimat[j]=='5'){
                   Push(&data,5);
               }else if(A[i].kalimat[j]=='6'){
                   Push(&data,6);
               }else if(A[i].kalimat[j]=='7'){
                   Push(&data,7);
               }else if(A[i].kalimat[j]=='8'){
                   Push(&data,8);
               }else if(A[i].kalimat[j]=='9'){
                   Push(&data,9);
               }else if(A[i].kalimat[j]=='_'){
                   Pop(&data, &hapus);
               }
           }
reverseList(&data);
           while(!IsEmpty(data)){

            Pop(&data, &hapus);

            cout << hapus << " ";
        }
    if(i+1<n){
        cout << endl;
    }
    }
}