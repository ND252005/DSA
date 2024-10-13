
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct node {
    int info;
    node *next;
};
struct List {
    node *pHead, *pTail;
};

node* get_node(int x) {
    node* p = new node;
    p->info = x;
    p->next = nullptr;
    return p;
}

void add_tail(List &L, int x) {
    node * p = get_node(x);
    if(!L.pHead){
        L.pHead = L.pTail = p;
    } else {
        L.pTail->next = p;
        L.pTail = p;
    }
}

void inputList(List &L, int n) {
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        add_tail(L, x);
    }
}

void outputList(List L) {
    node *p = L.pHead;
    if(L.pHead == nullptr) {
        cout << "List is empty";
        return;
    }
    while(p) {
        cout << p->info << ' ';
        p = p->next;
    }
}
node* findMiddle(List &L) {
    if(!L.pHead) {
        return nullptr;
    }
    int sl = 0;
    node *p = L.pHead;
    while(p) {
        sl++;
        p = p->next;
    }
    p = L.pHead;
    int mid = sl / 2 + 1;
    int dem = 1;
    while(dem < mid) {
        p = p->next;
        dem++;
    }
    return p;
}

int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L);
    cout<<endl;

    node *p=findMiddle(L); //Neu so phan tu chan thi co 2 phan tu chinh giua, chi xuat phan tu chinh giua thu 2
    if(p)cout<<"The middle element is "<<p->info;

    return 0;
}
