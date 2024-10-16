
#include <iostream>
#include <cstring>
#include <string>
using namespace std;


struct Node {
    int val;
    Node* next;
};
struct List {
    Node *head, *tail;
};

Node* get_node(int x) {
    Node * p = new Node;
    p->val = x;
    p->next = nullptr;
    return p;
}

void Init(List &L) {
    L.head = L.tail = nullptr;
}

void add_tail(List &L, int x) {
    Node *p = get_node(x);
    if(!L.head) {
        L.head = L.tail = p;
    } else {
        L.tail->next = p;
        L.tail = p;
    }
}

void inputList(List &L, int n) {
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        add_tail(L, tmp);
    }
}

void outputList(List L) {
    if(!L.head) cout << "List is empty" << endl;
    else {
        Node *p = L.head;
        while(p) {
            cout << p->val << ' ' ;
            p = p->next;
        }
        cout << endl;
    }
}

void copy(List l, List &l2) {
    Node * p1 = l.head, *p2 = l2.head;
    while(p1) {
        add_tail(l2, p1->val);
        p1 = p1->next;
    }
}

void concate(List l1, List l2) {
    if(!l1.head){
        copy(l2, l1);
        return;
    }
    if(!l2.head) {
        copy(l1, l2);
        return;
    }
    else {
        l1.tail ->next = l2.head;
    }
}




int main()
{
    List L1, L2;
    Init(L1);Init(L2);

    int n; cin>>n;
    inputList(L1,n);
    cout<<"Created 1st List: "<<endl;
    outputList(L1);
    cout<<endl;

    cin>>n;
    inputList(L2,n);
    cout<<"Created 2nd List: "<<endl;
    outputList(L2);
    cout<<endl;

    concate(L1,L2); // Noi L2 vao L1
    cout<<"Updated L1: "<<endl;
    outputList(L1);

    return 0;
}
