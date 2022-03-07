#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
struct data{
	int nim;
	string nama;
	string no;
};
class Node {
	public:
   		data isi;
		Node *next;
};

 


void insertAfter(Node* prev_node, data new_data)
{
    if (prev_node == NULL)
    {
        cout<<"The given previous node cannot be NULL";
        return;
    }
 
    Node* new_node = new Node();
 
    new_node->isi = new_data;
 
    new_node->next = prev_node->next;
 
    prev_node->next = new_node;
}
 
void append(Node** head_ref, data new_data)
{
    Node* new_node = new Node();
 
    Node *last = *head_ref; 
    
    new_node->isi = new_data;
 
    new_node->next = NULL;
 
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
 
    while (last->next != NULL)
    {
        last = last->next;
    }
 
    last->next = new_node;
    return;
}
void deleteNode(Node** head_ref, int key)
{
     
    Node* temp = *head_ref;
    Node* prev = NULL;
     
    if (temp != NULL && temp->isi.nim == key)
    {
        *head_ref = temp->next;
        delete temp;           
        return;
    }
 
      else
    {
    while (temp != NULL && temp->isi.nim != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    if (temp == NULL)
        return;
 
    prev->next = temp->next;
 
    delete temp;
    }
}
void printList(Node *node)
{
	int i;
	node=node->next;
    while (node != NULL)
    {
        cout<<i+1<<"\tNama :"<<node->isi.nama<<endl
        	<<"\tNIM :"<<node->isi.nim<<endl
        	<<"\tNomor Telpon :"<<node->isi.no<<endl;
        node = node->next;
    }
}
struct Node* head = NULL;
int main(){
	
	
	int n=0;
	int loc=0;
	Node* a=new Node();
	Node* b=new Node();
	cout<<"Masukan jumlah antrian pertama: ";
	cin>>n;
	string dummy;
	getline(cin,dummy);
	for(int i=0;i<n;i++){
		data antri;
		cout<<"Nama :";
		getline(cin,antri.nama);
		cout<<"NIM :";
		cin>>antri.nim;
		cout<<"Nomor Telpon :";	getline(cin,dummy);
		getline(cin,antri.no);
		append(&a,antri);
	}
	cout<<"Masukan jumlah antrian terakhir: ";
	cin>>n;
	for(int i=0;i<n;i++){
		data antri;
		cout<<"Nama :";
		getline(cin,antri.nama);
		getline(cin,antri.nama);
		cout<<"NIM :";
		cin>>antri.nim;
		cout<<"Nomor Telpon :";
		cin>>antri.no;
		append(&a,antri);
	}
	cout<<"Masukan jumlah NIM Yang Tidak hadir: ";
	cin>>n;
	for(int i=0;i<n;i++){
		int nim=0;
		cout<<"NIM :";
		cin>>nim;
		deleteNode(&a, nim);
	}
   cout<<"LIST: "<<endl;
   printList(a);
   return 0;
}
