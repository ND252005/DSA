
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
void delete_head_node(List &L) {
	Node *p = L.head->next;
	delete L.head;
	L.head = p;
	delete p;
}



void print_list(List L) {
	Node *p;
	p = L.head;
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
		if(x == 3) break;
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
	}
	print_list(L);

}