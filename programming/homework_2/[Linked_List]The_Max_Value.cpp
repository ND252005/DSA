
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

void add_after(List &L, int x) {
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
        add_after(L, x);
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

node* findMax(List L) {
    if(!L.head) {
        cout << "List is empty";
        return nullptr;
    }
    node *p = L.head;
    node *max = L.head;
    while(p) {
        if(p->info > max->info){
            max = p;
        }
        p = p->next;
    }
    return max;
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


    cout<<"\nThe maximum value: ";
    node *p = findMax(L);
    if(p) cout<<p->info;

    return 0;
}
