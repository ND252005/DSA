
#include <iostream>
#include <string>

#define LOAD 0.7
using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Node {
    Hocsinh data;
    Node *next;
};

struct List {
    Node * head, *tail;
};

struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    List *table;
};
void Input(Hocsinh &hs) {
    cin >> hs.Maso;
    getline(cin >> ws, hs.Hoten);
    cin >> hs.Gioitinh;
    cin >> hs.Namsinh;
    cin >> hs.TBK;
}

int Hash(Hashtable &H, int maso) {
    return maso % H.M;
}

void initList(List &l) {
    l.head = l.tail = nullptr;
}

void CreateHashtable(Hashtable &H, int m) {
    H.M = m;
    H.n = 0;
    H.table = new List[m];
    for(int i = 0; i < m; i++) {
        initList(H.table[i]);
    }
}
Node* get_node(Hocsinh hs) {
    Node* p = new Node();
    p->data = hs;
    p->next = nullptr;
    return p;
}

void AddTail(List &l, Hocsinh hs) {
    Node* p = get_node(hs);
    if(!l.head) {
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}
int Delete(Hashtable &H, int maso) {
    int key = Hash(H, maso);
    Node* current = H.table[key].head;
    if(!current) return 0;
    if(current->data.Maso == maso) {
        H.table[key].head = current->next;
        if(current == nullptr) {
            H.table[key].head = H.table[key].tail = nullptr;
        }
        delete current;
        H.n--;
        return 1;

    }
    while(current->next && current->next->data.Maso != maso) {
        current = current->next;
    }
    if(!current->next) {
        return 0;
    }
    Node *temp = current->next;
    current->next = temp->next;
    if(temp == H.table[key].tail) {
        H.table[key].tail = current;
    }
    delete temp;
    H.n--;
    return 1;
}

void PrintHashtable(Hashtable &H) {
    for(int i = 0; i < H.M; i++) {
        Node *current = H.table[i].head;
        if(current) {
            while(current) {
                Hocsinh &hs = current->data;
                cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "] ";
                current = current->next;        
            }
            cout << endl;
        } else {
            cout << endl;
        }
    }
}
void Deletelist(List &l) {
    Node *current = l.head;
    while(current) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    l.head = l.tail = nullptr;
}
void DeleteHashtable(Hashtable &H) {
    for(int i = 0; i < H.M; i++) {
        Deletelist(H.table[i]);
    }
    H.M = 0;
    H.n = 0;
    delete [] H.table;
    H.table = nullptr;
}

int main()
{
    Hashtable hashtable;

    int m, n, k;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    for (int i = 0; i < m; i++) {
        cin >> k;
        hashtable.n += k;
        for (int j = 0; j < k; j++) {
            Input(hs);
            AddTail(hashtable.table[i], hs);
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;

        if (Delete(hashtable, k) == 0)
            cout << "KHONG XOA DUOC\n";
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}
