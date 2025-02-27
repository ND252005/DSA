
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}

Node* get_node(int x) {
    Node *p = new Node;
    p->val = x;
    p->next = nullptr;
    return p;
}

void add_tail(List &l, int x) {
    Node *p = get_node(x);
    if(!l.head) {
        l.head = l.tail = p;
    } else {
        l.tail ->next = p;
        l.tail = p;
    }
}

void copy(List l, List &l2) {
    Node * p1 = l.head, *p2 = l2.head;
    while(p1) {
        add_tail(l2, p1->val);
        p1 = p1->next;
    }
}



int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    List l; list_initializing(l);
    //Read list
    int x;
    do{
        cin >> x;
        add_tail(l, x);
    } while(x != 0);

    List l2; list_initializing(l2);
    copy(l, l2);

    Node*p = l.head, *q = l2.head;
    while(p != NULL){
    	if (p == q || p->val != q->val) cout << "WRONG";
    	cout << p->val << endl;
    	p = p->next;
    	q = q->next;
    }

    return 0;
}
