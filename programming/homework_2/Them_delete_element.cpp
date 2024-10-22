
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

void delete_element(List &l, int n) {
    if(!l.head) {
        return;
    } else if(l.head->info == n) {
        if(l.head == l.tail) {
            l.head = l.tail = nullptr;
        } else {
            Node *tmp = l.head;
            l.head = l.head ->next;
            delete tmp;
            return;
        }
    } else {
        Node *pre = l.head;
        Node *cur = l.head->next;
        while(cur) {
            if(cur->info == n) {
                pre->next = cur->next;
                if(cur == l.tail) {
                    l.tail = pre;
                }
                delete cur;
                return;
            }
            pre = cur;
            cur = cur->next;
        }
    }
}

void delete_multi_element(List &l, int n) {
    if(!l.head){
        return;
    }
    while (l.head && l.head->info == n) {
        Node *temp = l.head;
        if (l.head == l.tail) {
            l.head = l.tail = nullptr;
        } else {
            l.head = l.head->next;
        }
        delete temp; 
    }

    if (!l.head) {
        return; 
    }

    Node *pre = l.head;
    Node *cur = l.head->next;
    while (cur) {
        if (cur->info == n) {
            pre->next = cur->next;
            if (cur == l.tail) {
                l.tail = pre;
            }
            Node *temp = cur;
            cur = cur->next;
            delete temp;
        } else {
            pre = cur;
            cur = cur->next;
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
            Node *p = L.head;
            L.head = p->next;
            p = nullptr;
        }
    }
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
		if (x == 0) { 
			int y; cin >> y;//them y vao dau danh sach lien ket 
			add_head(L, y);
		}
		else if(x == 1) {
			int y; cin >> y;//them y vao dau danh sach lien ket 
			add_tail(L, y);
		}
		else if(x == 2) {
			int a, b; cin >> a >> b;
			add_after(L, a, b); 
		}
        else if(x == 3) {
            int n; cin >> n;
            delete_element(L, n);
        }
        else if(x == 4) {
            int n; cin >> n;
            delete_multi_element(L, n);
        }
        else if(x == 5) {
            delete_head(L);
        }
        else if(x == 6) break;
	}
	print_list(L);
}