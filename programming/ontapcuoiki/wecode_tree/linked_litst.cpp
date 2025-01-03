#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

struct List {
    Node* head, *tail;
};

Node* get_node(int x) {
    Node *p = new Node();
    p->info = x;
    p->next = nullptr;
    return p;
}

void addHead(List &l, int x) {
    Node *p = get_node(x);
    if(!l.head) {
        l.head = l.tail = p;
    } else {
        p->next = l.head;
        l.head = p;
    }
}
void addTail(List &l, int x) {
    Node *p = get_node(x);
    if(!l.head) {
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}
void deleteHead(List &l) {
    if(!l.head) {
        return;
    } else if(l.head == l.tail) {
        l.head = l.tail = nullptr;
    } else  {
        Node *p = l.head;
        l.head = l.head->next;
        p = nullptr;
        delete p; 
    }
}
void deleteTail(List &l) {
    if(!l.head) {
        return; 
    } else if(l.head == l.tail) {
        l.head = l.tail = nullptr;
    } else {
        Node *p = l.head;
        while(p->next != l.tail) {
            p = p->next;
        }
        Node* p1 = l.tail;
        l.tail = p;
        p1 = nullptr;
        delete p1;
    }
}
void delete_Q(List &l, int x) {
    Node *p = get_node(x);
    if(!l.head) {
        return;
    } else if(p->info == l.head->info) {
        l.head ->next = l.head;
    } else {

    }
}
void delete_after_Q(List &l, int x) {
    if(!l.head || l.tail->info == x) {
        return;
    } else {
        Node *p = l.head;
        while(p->info != x && p) {
            p = p->next;
        }
        if(p) {
            Node *px = p->next;
            p->next = p->next->next;
            if(px == l.tail) l.tail = p; 
            px = nullptr;
            delete px;
        }
    }
}


