#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

struct List {
    Node *head, *tail;
};

Node* get_node(int x) {
    Node *p = new Node();
    p->info = x;
    p->next = nullptr;
    return p;
}

void addTail(List &l, int x) {
    Node *p = get_node(x);
    if(!l.head) {
        l.head = l.tail = p;
        return;
    }
    l.tail->next = p;
    l.tail = p;
}

void addHead(List &l, int x) {
    Node *p = get_node(x);
    if(!l.head) {
        l.head = l.tail = p;
        return;
    }
    p->next = l.head;
    l.head = p;
}

void addAfterQ(List &l, Node *p, Node* q) {
    if(q) {
        Node* nxt = q->next;
        q->next = p;
        p->next = nxt;
        if(q == l.tail) l.tail = p; 
    }
}

void removeHead(List &l) {
    if(l.head) {
        if(l.head == l.tail) {
            delete l.head;
            l.head = l.tail = nullptr;
        } else {
            Node *current = l.head; 
            l.head = l.head->next;
            delete current;
        }
    }
}

int removeQ(List &l, Node* q) {
    if(q && l.head) {
        if(q == l.head) {
            removeHead(l);
            return 1;
        }
        Node* p = l.head;
        while(p->next && p->next != q) {
            p = p->next;
        }
        if(p->next == q) {
            p->next = q->next;
            if(q == l.tail) l.tail = p;
            delete q;
            return 1;
        }
    }
    return 0;
}

void printList(const List &l) {
    Node* p = l.head;
    while(p) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    List myList;
    myList.head = myList.tail = nullptr;

    cout << "Adding elements at the tail: 10, 20, 30" << endl;
    addTail(myList, 10);
    addTail(myList, 20);
    addTail(myList, 30);
    printList(myList);

    cout << "Adding elements at the head: 5" << endl;
    addHead(myList, 5);
    printList(myList);

    cout << "Adding 15 after the second node (value 10):" << endl;
    Node* secondNode = myList.head->next;
    addAfterQ(myList, get_node(15), secondNode);
    printList(myList);

    cout << "Removing the head:" << endl;
    removeHead(myList);
    printList(myList);

    cout << "Removing a specific node (value 20):" << endl;
    Node* nodeToRemove = myList.head->next->next; // Node with value 20
    removeQ(myList, nodeToRemove);
    printList(myList);

    cout << "Final list:" << endl;
    printList(myList);

    return 0;
}
