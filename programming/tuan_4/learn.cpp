#include <iostream>
using namespace std;

struct Node {
    int info; 
    Node *next;
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
void insert_head( List &L, int x) {
    Node *p = get_node(x);
    if(!L.head) {
        L.head = L.tail = p;
        return;
    } else {
        p->next = L.head;
        L.head = p;    
    }
}
void insert_tail(List &L, int x) {
    Node *p = get_node(x);
    if(L.head){
        L.tail ->next = p;
        L.tail = p;
    } else {
        L.head = L.tail = p;
    }
}
void insert_back_element(List &L, int a, int b) {
    Node *px = get_node(a);
    if (!L.head) return; 

    if (L.head == L.tail) { // Trường hợp danh sách có một phần tử
        if (L.head->info == b) {
            L.head->next = px;
            L.tail = px;
        }
        return;
    } 

    // Duyệt danh sách để tìm node chứa giá trị b
    Node *pre = L.head;
    while (pre != nullptr && pre->info != b) {
        pre = pre->next;
    }

    if (pre == nullptr) {
        // Không tìm thấy giá trị b trong danh sách
        return;
    }

    // Nếu pre là L.tail, chèn vào cuối danh sách
    if (pre == L.tail) {
        insert_tail(L, a);
    } else {
        // Chèn px vào sau pre
        Node *p = pre->next;
        pre->next = px;
        px->next = p;
    }
}

void delete_head(List &L) {
    if(!L.head) {
        return;
    } else if(L.head == L.tail) {
        L.head = L.tail = nullptr;
    } else {
        Node *pa = L.head->next;
        Node *pb = L.head;
        L.head = pa;
        pb->next = nullptr;
        
    }
}
void delete_tail(List &L) {
    if(!L.head) return;
    else if(L.head == L.tail) {
        L.head = L.tail = nullptr;
    } else {
        Node *p = L.head;
        while(p->next != L.tail) {
            p = p->next;
        }
        delete p->next;
        p->next = nullptr;
        L.tail = p;
    }
}
void delete_element(List &L, int x) {
    if(!L.head) return;
    if(L.head->info == x) {
        Node *dau = L.head;
        if(L.head == L.tail) {
            delete dau; 
            L.head = L.tail = nullptr;
        } else {
            L.head = dau->next;
            delete dau;
        }
    }
    else if(L.head == L.tail) {
        Node *p = L.head;
        delete p;
        L.head = L.tail = nullptr;
    }
    else {
        Node *p = L.head;
        while(p->next && p->next->info != x) {
            p = p->next;
        }
        if(p->next) {
            Node * back = p->next;
            p->next = back->next;
            if(back == L.tail) L.tail = p;
            delete back;
        }
    } 
}
void output(List L) {
    Node *p = L.head;
    while(p) {
        cout << p->info << ' ';
        p = p->next;
    }
}
int main() {
    List L;
    L.head = L.tail = nullptr;
    while(true) {
        int x; cin >> x;
        if(x == 0) {
            int y; cin >> y;
            insert_head(L, y);
        }
        if(x == 1) {
            int y; cin >> y;
            insert_tail(L, y);
        }
        if(x == 2) {
            int a, b; cin >> a >> b;
            insert_back_element(L, a, b);
        }
        if(x == 3) {
            int y; cin >> y;
            delete_element(L, y);
        }
        if(x == 4) {
            delete_tail(L);
        }
        if(x == 5) {
            delete_head(L);
        }
        if(x == 6) break;
    }
    output(L);
}