#include <iostream>
using namespace std;

#define Nil NULL
#define MaxEl 10

typedef int infotype;
typedef struct tNode *addrNode;
typedef struct tNode
{
    infotype info;
    addrNode next;
};

typedef struct tHash *addrHash;
typedef struct tHash{
    addrNode first;
} Hash;

#define Info(P)         (P)->info
#define Next(P)         (P)->next
#define First(H, i)     (H)[i].first

void createEmptyHash(addrHash hash_table){
    for (int i = 0; i < MaxEl; i++)
    {
        First(hash_table, i) = Nil;
    }
}

addrNode nodeAllocation(infotype X){
    addrNode NewNode;
    NewNode = (Node*) malloc (sizeof(Node));

    NewNode->info = X;
    Next(NewNode) = Nil;

    return NewNode;
}

void nodeDeallocation (addrNode hapus){
    free(hapus);
}

bool isEmptyFirst(addrNode First){
    return(First == Nil);
}

void insertFirst(addrNode *First, infotype X){
    addrNode NewNode = nodeAllocation(X);
    Next(NewNode) = *First;
    *First = NewNode;
}

void insertLast(addrNode *First, infotype X){
    addrNode NewNode = nodeAllocation(X);
    addrNode temp;
    temp = *First;
    while(Next(temp) != Nil){
        temp = Next(temp);
    }
    Next(temp) = NewNode;
}

void deleteFirtst(addrNode *First){
    addrNode temp = *First;
    First = Next(*First);
    Next(temp) = Nil;
    nodeDeallocation(temp);
}

void deleteAfter(addrNode *pred){
    addrNode temp;
    temp = Next(*pred);
    Next(*pred) = Next(temp);
    nodeDeallocation(temp);
}

void deleteLast(addrNode *First){
    addrNode temp, predTemp;
    predTemp = Nil;
    temp = *First;
    while(Next(temp) != Nil){
        temp = Next(temp);
    }
    deleteAfter(&predTemp);
}

void insertValue(addrHash hash_table, infotype X){
    int index = X % MaxEl;
    addrNode *First = &(First(hash_table, index));

    if(isEmptyFirst(*First)){
        insertFirst(First, X);
    } else insertLast(First, X);
}

void deleteValue (addrHash hash_table, infotype X){
    int index = X % MaxEl;
    addrNode *First = &(First(hash_table, index));

    if(isEmptyFirst(*First)){
        cout << "Data tidak ditemukan";
    } else {
        if((*First) -> info == X){
            deleteFirtst(First);
        } else{
            addrNode temp;
            temp = *First;

            while (Next(temp) != Nil){
                temp = Next(temp);
                if (Info(temp) == X){
                    break;
                }
                
            }
            
        }
        
    }
}

void printAllValue(addrHash hash_table){
    addrNode temp;
    for (int i = 0; i < MaxEl; i++)
    {
        cout << endl << i << " -> ";

        if(First(hash_table, i) != Nil){
            temp = First(hash_table, i);
            while(temp != Nil){
                cout << Info(temp) << ", ";
                temp = Next(temp);
            }
        } else{
            cout << "Nil";
        }
        
    }
    
}
int main()
{
    // Array
    tHash th[MaxEl];
    createEmptyHash(th);

    insertValue(th, 15);
    insertValue(th, 44);
    insertValue(th, 65);
    insertValue(th, 35);
    insertValue(th, 78);

    printAllValue(th);

    return 0;
}
