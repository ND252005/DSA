
#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;

struct node {
    int info;
    node *next;
};

node* get_node(int x) {
	node *p = new node;
	p->info = x;
	p->next = nullptr;
	return p;
}

struct Hash {
    int m;
    node ** bucket; // con tror chuwas casc con tror ddauaf 
};

void initHash(Hash &H) {
    H.bucket = new node*[H.m];
    for(int i = 0; i < H.m; i++) {
        H.bucket[i] = nullptr; // moi bucket coi nhu mot head trong linked list
    }
}

int hash_funct(Hash H, int key) {
    return key%H.m; 
}


void add_head(node *&L, int x) {
	node *p = get_node(x);
	if(L == nullptr) {
		L = p;
	} else {
		p->next = L;
		L = p;
	}
}


void add_after(node *L, node *&q, int x) {
    node *p = get_node(x);
    if(q->next == nullptr) {
        q->next = p;
    } else {
        p->next = q->next;
        q->next = p;
    }
}


void insertList(node *&L, int x) {
    node *new_ele = get_node(x);
    node *p = L, *q = nullptr;
    while(p && (x > p->info)) {
        q = p;
        p = p->next;
    }
    if(q == nullptr)
        add_head(L, x);
    else 
        add_after(L, q, x);
}

void insertHash(Hash &H, int x) {
    //Tim dia chi 
    int index = hash_funct(H,x);
    //them x vao dslk thuws index
    insertList(H.bucket[index], x);
}

void traverseAllHash(Hash H) {
    for(int i = 0; i < H.m; i++) {
        node *p = H.bucket[i];
        cout << "Bucket " << i << ": ";  
        while(p) {
            cout << p->info << ' '; 
            p = p->next;
        }
        cout << endl;
    }
}

int main()
{
    Hash H;
    cin>>H.m; // m la so dia chi co trong bang bam
    initHash(H); //khoi tao cac bucket

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"Created Hash:"<<endl;
    traverseAllHash(H); // Xuat toan bo cac bucket cua Bang bam

    return 0;
}

