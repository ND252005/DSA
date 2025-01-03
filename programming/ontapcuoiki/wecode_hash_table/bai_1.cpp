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
int Hash(Hashtable H, int maso) {
    return maso % H.M;
}
void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
/*
MỘT SỐ GỢI Ý:
    Hàm CreateHashtable(hashtable, m) khởi tạo bảng băm
    {
        Bước 1: vì table được hiểu là 1 con trỏ quản lý 1 mảng động nên cần cấp phát vùng nhớ cho mảng các List
        lúc này, ở mỗi List đã có 2 con trỏ head và tail nhưng các con trỏ chưa khởi tạo
        Bước 2: Lần lượt khởi tạo con trỏ head, tail của mỗi List, nên viết hàm initList riêng
        Bước 3: khởi tạo các thuộc tính còn lại của bảng băm là M,n
    }
    Hàm Insert(hashtable, hs) thêm 1 học sinh hs vào bảng băm. Có thể thiết kế Hàm Insert sẽ trả về kết quả 1 nếu thêm phần tử thành công và trả về 0 nếu không thêm phần tử được
    {
        Kiểm tra hệ số tải. Hệ số tải của bảng băm được ấn định là 0.7, nghĩa là bảng băm luôn đảm bảo số phần tử được lưu trong bảng băm không quá 70% kích thước của bảng băm.
        Tìm địa chỉ phù hợp cho hs
        Từ địa chỉ này sẽ xác định được List mà hs thuộc về
        Gọi hàm thêm 1 phần tử vào List, nên viết hàm addHead hay addTail riêng
        Nhớ tăng số lượng phần tử của bảng băm
    }
    Hàm  PrintHashtable(hashtable) in bảng băm
    {
        Duyệt từng địa chỉ hay còn hiểu là duyệt từng List
            Ứng với mỗi List, xuất tất cả các phần tử trong List theo 1 format quy ước (ghi trong đề)
    }
    Hàm DeleteHashtable(hashtable) xóa toàn bộ bảng băm
    {
        Duyệt từng địa chỉ hay còn hiểu là duyệt từng List
            Ứng với mỗi List, xóa toàn bộ node trong danh sách, vì 2 con trỏ head, tail là biến tĩnh nên chỉ có thể gán về NULL
        Xóa vùng nhớ của mảng các List (vì cũng là mảng động), cũng nên gán lại con trỏ table về NULL cho an toàn
        Reset các thuộc tính còn lại của bảng băm

    }

*/
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
Node *get_node(Hocsinh hs) {
    Node *p = new Node();
    p->data = hs;
    p->next = nullptr;
    return p;
}
void addTail(List &l, Hocsinh hs) {
    Node *p = get_node(hs);
    if(!l.head) {
        l.head = l.tail = p; 
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}
void Insert(Hashtable &H, Hocsinh hs) {
    if((float)(H.n + 1)/H.M > LOAD) {
        return;
    }
    int index = Hash(H, hs.Maso);
    addTail(H.table[index], hs);
    H.n++;
}
void PrintHashtable(Hashtable &H) {
    for(int i = 0; i < H.M; ++i) {
        Node* current = H.table[i].head;
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
void DeleteList(List &l) {
    Node* current = l.head;
    while(current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    l.head = l.tail = nullptr;
}
void DeleteHashtable(Hashtable &H) {
    for(int i = 0; i < H.M; i++) {
        DeleteList(H.table[i]);
    }
    delete[] H.table;
    H.table = nullptr;
    H.M = 0;
    H.n = 0;
}



int main()
{
    Hashtable hashtable;

    int m, n;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    cin >> n;
    for (int i = 0; i < n; i++) {
        Input(hs);
        Insert(hashtable, hs);
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}
