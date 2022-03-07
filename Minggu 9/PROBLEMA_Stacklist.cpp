// Problem A StackList

#include <iostream>
#include <stdlib.h>
using namespace std;

/* Konstanta */
#define Nil NULL

/* Deklarasi infotype */
typedef int infotype;

/* Stack dengan representasi berkait dengan pointer */
typedef struct tElmtStack * address;
typedef struct tElmtStack {
    infotype Info;
    address Next;
} ElmtStack;

/* Type stack dengan ciri TOP : */
typedef struct {
    address TOP;  /* alamat TOP: elemen puncak */
} Stack;

/* Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).TOP->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/*    ----- Prototype Manajemen Memori ----- */
void Alokasi (address * P, infotype X) {
    /* Kamus Lokal */

    /* Algoritma */
    (*P) = (address) malloc (sizeof (ElmtStack));
    if ((*P) != Nil) {
        Info(*P) = X;
        Next(*P) = Nil;
    }
}

void Dealokasi (address P) {
    /* Kamus Lokal */

    /* Algoritma */
    Next(P)=Nil;
}

/* *** PROTOTYPE REPRESENTASI LOJIK STACK *****/
bool IsEmpty (Stack S) {
    /* Kamus Lokal */

    /* Algoritma */
    return (Top(S) == Nil);
}
void CreateEmpty (Stack * S) {
    /* Kamus Lokal */

    /* Algoritma */
    Top(*S) = Nil;
}
/*    ----- Operator Dasar Stack ----- */
void Push (Stack * S, infotype X) {
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    Alokasi(&P,X);
    if (P != Nil) {
        Next(P) = Top(*S);
        Top(*S) = P;
    }
}

void Pop (Stack * S, infotype * X) {
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = Top(*S);
    *X= Info(P);
    if (!IsEmpty(*S)) {
        Top(*S)=Next(P);
        Dealokasi(P);
    }
}

void printInfo (Stack S,int sum){
    if(!IsEmpty(S)){
        address P = Top(S);
        while(Next(P)!=Nil){
            cout<<Info(P)<<endl;
            P = Next(P);
        }
        cout<<Info(P);
        cout<<endl;
        cout<<sum;
    }else{
    cout<<"Stack kosong";
    }
    }

int main (){
    Stack S;
    CreateEmpty(&S);

    int n,sum=0;

    cin>>n;

    infotype x[n];
    for(int i=0; i<n; i++){
        cin>>x[i];
        Push(&S, x[i]);
        sum=sum+x[i];

 }
    printInfo(S,sum);

    return 0;
}