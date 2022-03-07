// Problem B

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct TElmtQueue *address;
typedef struct TElmtQueue {
    infotype info;
    address next;
} ElmtQueue;

typedef struct {
    address HEAD;
    address TAIL;
} Queue;


#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define Next(P)     (P)->next
#define InfoHead(P) (P)->info




void CreateEmpty(Queue* Q) {
    Head(*Q) = NULL;
    Tail(*Q) = NULL;
}

bool IsEmpty(Queue Q) {
    return ((Head(Q)==NULL) && (Tail(Q)==NULL));
}

address Allocation(infotype x) {
    address NewElmt;
    NewElmt = (ElmtQueue*) malloc (sizeof(ElmtQueue));

    if(NewElmt == NULL) {
        return NULL;
    }

    NewElmt->info = x;
    Next(NewElmt) = NULL;
    return NewElmt;
}

void Deallocation(address hapus) {
    free(hapus);
}


void ADD(Queue* Q, infotype x) {
    address temp = Allocation(x);

    if(temp!=NULL) {
        if(IsEmpty(*Q)) {
            Head(*Q) = temp;
            Tail(*Q) = temp;
        } else {
            Next(Tail(*Q)) = temp;
            Tail(*Q) = temp;
        }
    }
}


void Del(Queue *Q, infotype *hapus) {

    if (!IsEmpty(*Q)) {

        address temp;
        temp = Head(*Q);
        *hapus=InfoHead(temp);

        if(Head(*Q)==Tail(*Q)) {
            Deallocation(temp);
            Head(*Q) = NULL;
            Tail(*Q) = NULL;

        } else {
            Head(*Q) = Next(Head(*Q));
            Next(temp) = NULL;
            Deallocation(temp);
        }
    }
}



struct input{
        string kata;

};



int main () {

    int hapus=0;



    int n,i,j;
    cin>>n;
    input X[n];

    for(i=0; i<n; i++){
        cin>>X[i].kata;
    }
     Queue Q;
     CreateEmpty(&Q);

     for(i=0; i<n; i++){
        for(j=0; j<((X[i].kata).length()); j++){

            if (X[i].kata[j] == '0'){
                ADD(&Q, 0);
            }else if (X[i].kata[j] == '1'){
                ADD(&Q, 1);
            }else if (X[i].kata[j] == '2'){
                ADD(&Q, 2);
            }else if (X[i].kata[j] == '3'){
                ADD(&Q, 3);
            }else if (X[i].kata[j] == '4'){
                ADD(&Q, 4);
            }else if (X[i].kata[j] == '5'){
                ADD(&Q, 5);
            }else if (X[i].kata[j] == '6'){
                ADD(&Q, 6);
            }else if (X[i].kata[j] == '7'){
                ADD(&Q, 7);
            }else if (X[i].kata[j] == '8'){
                ADD(&Q, 8);
            }else if (X[i].kata[j] == '9'){
                ADD(&Q, 9);
            }else if (X[i].kata[j] == '_'){
                Del(&Q, &hapus);
            }
        }
        while(!IsEmpty(Q)){
            Del(&Q, &hapus);
            cout<<hapus<<" ";
        }

        if(i+1<n){
            cout<<endl;
        }
    }
}