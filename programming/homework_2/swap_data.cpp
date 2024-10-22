#include <iostream>
#include <cstring>
#include <string>
using namespace std;


struct node {
    int info;
    node* next;
};
struct List {
    node *pHead, *pTail;
};

node* get_node(int x) {
    node * p = new node;
    p->info = x;
    p->next = nullptr;
    return p;
}

void add_tail(List &L, int x) {
    node *p = get_node(x);
    if(!L.pHead) {
        L.pHead = L.pTail = p;
    } else {
        L.pTail->next = p;
        L.pTail = p;
    }
}

void inputList(List &L, int n) {
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        add_tail(L, tmp);
    }
}

void outputList(List L) {
    if(!L.pHead) {
        cout << "List is empty";
        return;
    } else {
        node *p = L.pHead;
        while(p) {
            cout << p->info << ' ';
            p = p->next;
        }
        cout << endl;
    }
}
node* swapData(List &L, int x, int y) {
    if(!L.pHead) {
        return nullptr;
    } else {
        node *px = L.pHead;
        node *py = L.pHead;

        while(px) {
            if(px ->info == x) break;
            px = px->next;
        }
        while(py) {
            if(py ->info == y) break;
            py = py->next;
        }
        if(px == nullptr || py == nullptr) {
            return nullptr;
        }

        swap(px->info, py->info);
        return px;
    }
}


int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L); // Neu ds rong thi xuat "List is empty"
    cout<<endl;

    int x, y; cin>>x>>y;
    node *p = swapData(L,x,y);
    /* Tim 2 node chua x va y,
    Hoan vi gia tri cua 2 node do,
    nghia la: Lien ket giua cac node khong thay doi, node ban dau chua x se doi lai la chua y
    Ham return node chua x ban dau, luc chua hoan vi*/

    cout<<"Updated List after swapping "<<x<<" and "<<y<<": "<<endl;
    outputList(L);
    cout<<endl;

    /* Kiem tra xem co that su hoan vi info cua 2 node khong
    Neu hoan vi info thi node chua x ban dau se doi lai chua y*/

    if(p) // co hoan vi
    {
        cout<<"At the address of "<<x<< ": ";
        cout<<p->info;
    }
    else cout<<"Can not swap";
    return 0;
}
