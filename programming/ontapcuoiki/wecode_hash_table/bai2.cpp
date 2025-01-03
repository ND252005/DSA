
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
void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Gioitinh;
    cin >> x.Namsinh;
    cin >> x.TBK;
}
/*MỘT SỐ LƯU Ý TRONG TEMPLATE NÀY
Trong các bài tập Search, Delete, input là bảng băm đã có.
Tức là trước đó, GV đã thêm các phần tử vào bảng băm (theo đúng kỹ thuật của bài Insert),
sau đó xuất toàn bộ bảng băm đó ra file inputx.txt (lần lượt xuất từng List ứng với mỗi địa chỉ).

Đoạn code bên dưới tái hiện lại bảng băm đã có nên SV không cần viết lại hàm Insert, chỉ cần tập trung vào chức năng Search
for (int i = 0; i < m; i++) { //duyệt từng List ứng với mỗi địa chỉ
        cin >> k; //số phần tử trong List[i]
        hashtable.n += k; //tăng số lượng phần tử trong bảng băm theo số lượng phần tử của List[i]
        for (int j = 0; j < k; j++) { //lần lượt nhập k học sinh và thêm vào cuối danh sách List[i]
            Input(hs);
            AddTail(hashtable.table[i], hs);
        }
}
*/

int Hash(Hashtable H, int maso) {
    return maso %H.M;
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
    Node *p = get_node(hs);
    if(!l.head) {
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}
Node* Search(Hashtable &H, int maso) {
    int key = Hash(H, maso);
    Node *p = H.table[key].head;
    while(p && p->data.Maso != maso) {
        p = p->next;
    }
    return p;
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
        Node * p = Search(hashtable, k);

        if (p == NULL)
            cout << "KHONG TIM THAY\n";
        else {
            hs = p->data;
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "]\n";
        }
    }
    DeleteHashtable(hashtable);
    return 0;
}
