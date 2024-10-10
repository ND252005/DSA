
#include <iostream>
using namespace std;

struct Node {
	int info;
	Node* next;
};

struct List {
	Node *head, *tail, *insert;

};

Node *get_node(int x) {
	Node *p = new Node;
	p->info = x;
	p->next = nullptr;
	return p;
}

void add_head(List &L, int x) {
	Node *p = get_node(x);
	if(L.head == nullptr) {
		L.head = L.tail = p;
	} else {
		p->next = L.head;
		L.head = p;
	}
}

void add_tail(List &L, int x) {
	Node *p = get_node(x);
	if(L.head == nullptr) {
		L.head = L.tail = p;
	} else {
		L.tail->next = p;
		p->next = nullptr;
		L.tail = p;
	}
}


void add_after(List &L, int a, int b) {
	Node *p = get_node(b);
	if(L.head == nullptr) {
		L.head = L.tail = p;
	} else {
		Node *i, *chay;
		i = L.head;
		while(i != nullptr) {
			if(i->info == a){
				chay = i->next;
				break;
			}
			i = i->next;
		}
		if(i == L.tail){
			add_tail(L,b);
		} 
		else if(i != nullptr){
			p->next = chay;
			i->next = p;
		} else {
			add_head(L, b);
		}
	}
}



void delete_head(List &l){
    Node *p = l.head;
    if(l.head != nullptr){
        l.head = p->next;
       if (l.head == nullptr) {
            l.tail = nullptr; // List is now empty
        }
        delete p; // Free memory
    }
}

void print_list(List L) {
	Node *p;
	p = L.head;
    if(p == nullptr) cout << "blank";
	while(p != nullptr) {
		cout << p->info << ' ';
		p = p->next;
	}
}

int main() {
	List L;
	L.head = L.tail = L.insert = nullptr;
	while(1){
		int x; cin >> x;
		if(x == 6) break;
		if (x == 0) { 
			int y; cin >> y;//them y vao dau danh sach lien ket 
			add_head(L, y);
		}
		if(x == 1) {
			int y; cin >> y;//them y vao dau danh sach lien ket 
			add_tail(L, y);
		}
		if(x == 2) {
			int a, b; cin >> a >> b;
			add_after(L, a, b); 
		}
        if(x == 5) {
            delete_head(L);
        }
	}
	print_list(L);

}