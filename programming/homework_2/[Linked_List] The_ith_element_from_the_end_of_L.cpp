
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct node {
    int info;
    node *next;
};
struct List {
    node *head, *tail;
};

node* get_node(int x) {
    node* p = new node;
    p->info = x;
    p->next = nullptr;
    return p;
}

void add_tail(List &L, int x) {
    node * p = get_node(x);
    if(!L.head){
        L.head = L.tail = p;
    } else {
        L.tail->next = p;
        L.tail = p;
    }
}


void Init(List &L){
    L.head = L.tail = nullptr;
}

void inputList(List &L, int n) {
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        add_tail(L, x);
    }
}

void outputList(List L) {
    node *p = L.head;
    if(L.head == nullptr) {
        cout << "List is empty";
        return;
    }
    while(p) {
        cout << p->info << ' ';
        p = p->next;
    }
}

node* findElementFromEnd(List L, int i) {
    if(!L.head) {
        cout << "List is empty";
        return nullptr;
    } else {
        int sl = 0;
        node *p = L.head;
        while(p){
            sl++;
            p = p->next;
        }
        if(i > sl || i < 0){
            cout << "The index is invalid";
            return nullptr;
        }
        int index = sl - i;
        p = L.head;
        for(int j = 0; j < index; j++) {
            p = p->next;
        }
        return p;   
    }
}



int main()
{
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);

    int i; cout<<"\nEnter a number: "; cin>>i;
    cout<<"\nThe element at index "<<i<<" (from the end of L): ";
    node *p = findElementFromEnd(L,i);
    if(p) cout<<p->info;


    return 0;
}
