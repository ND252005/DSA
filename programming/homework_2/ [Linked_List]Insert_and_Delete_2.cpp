#include <iostream>
using namespace std;

struct type {
    char x, y;
    int z;
};

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

void add_head(List &L, int x) {
    node *p = get_node(x);
    if(!L.head){
        L.head = L.tail = p;
    } else {
        p->next = L.head;
        L.head = p;
    }
}

void delete_tail(List &L) {
    if(!L.head) {
        return;
    } else {
        if(L.head == L.tail) {
            L.head = L.tail = nullptr;
        } else {
            node *p = L.head;
            while(p->next != L.tail){
                p = p->next;
            }
            L.tail = nullptr;
            p->next = nullptr;
            L.tail = p;
        }
    }
}

void delete_head(List &L) {
    if(!L.head){
        return;
    } else {
        if(L.head == L.tail) {
            L.head = L.tail = nullptr;
        } else {
            node *p = L.head;
            L.head = p->next;
            p = nullptr;
        }
    }
}

void Init(List &L){
    L.head = L.tail = nullptr;
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

void process(List &L, int n) {
    for(int i = 0; i < n; i++) {
        type T;
        cin >> T.x >> T.y >> T.z;
        if(T.x == '+') {
            if(T.y == 'H')
                add_head(L, T.z);
            else add_tail(L, T.z);
        } else {
            if(T.y == 'H')
                delete_head(L);
            else delete_tail(L);
        }
    }
}

int main() {
    List L; Init(L);
    int n; cin >> n;
    process(L, n);
    outputList(L);
}