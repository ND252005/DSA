
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct node {
    int info;
    node* next;
};
struct List {
    node *pHead, *pTail;
};

node* get_node(int x) {
    node * p = new node;
    p->info = x;
    p->next = nullptr;
    return p;
}

void add_tail(List &L, int x) {
    node *p = get_node(x);
    if(!L.pHead) {
        L.pHead = L.pTail = p;
    } else {
        L.pTail->next = p;
        L.pTail = p;
    }
}

void inputList(List &L, int n) {
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        add_tail(L, tmp);
    }
}

void outputList(List L) {
    if(!L.pHead) {
        cout << "List is empty";
        return;
    } else {
        node *p = L.pHead;
        while(p) {
            cout << p->info << ' ';
            p = p->next;
        }
        cout << endl;
    }
}

void moveLastToFront(List &L) {
    if(!L.pHead || L.pHead == L.pTail) {
        return;
    }
    node* p = L.pHead;
    while(p->next != L.pTail) {
        p = p->next;
    }
    L.pTail ->next = L.pHead;
    L.pHead = L.pTail;
    L.pTail = p;
    p ->next = nullptr;
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

    moveLastToFront(L); //di chuyen node cuoi ve dau danh sach
    cout<<"Updated List after moving the last element to front of L: "<<endl;
    outputList(L);
    return 0;
}
