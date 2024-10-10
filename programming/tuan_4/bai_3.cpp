
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
            l.tail = nullptr; 
        }
        delete p; 
    }
}
void delete_n_number(List &L, int n) {
    if (L.head == nullptr) return;  // If the list is empty

    Node *current = L.head;
    Node *previous = nullptr;

    // Search for the node with info == n
    while (current != nullptr) {
        if (current->info == n) {
            // Found the node to delete
            if (current == L.head) {
                // Deleting the head node
                delete_head(L);
            } else {
                // Deleting a non-head node
                previous->next = current->next;
                if (current == L.tail) {
                    L.tail = previous;  // Update tail if needed
                }
                delete current;
            }
            return;
        }
        previous = current;
        current = current->next;
    }
    // If the number `n` is not found, do nothing
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
        if(x == 3) {
            int n; cin >> n;
            delete_n_number(L, n);
        }
	}
	print_list(L);

}