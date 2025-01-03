#include <iostream>
#include <string>

#define LOAD 0.7
#define EMPTY 0
#define DELETE -1
using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    Hocsinh *table;
};
void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
void CreateHashtable(Hashtable& H, int m) {
    H.M = m;
    H.n = 0;
    H.table = new Hocsinh[m];
    for (int i = 0; i < m; i++) {
        H.table[i].Maso = EMPTY;
    }
}
int Hash(Hashtable &H, int maso) {

    for(int i = 0; i < H.M; i++) {
        int index = ((maso % H.M) + i) % H.M;
        if(H.table[index].Maso == EMPTY || H.table[index].Maso == DELETE) {
            return index;
        } 
    }
    return -1;
}
int Insert(Hashtable& H, Hocsinh x) {
    if ((H.n + 1) > H.M * LOAD)
        return 0;
    int index = Hash(H, x.Maso);
    if(index != -1) {
        H.table[index] = x;
        H.n++;
        return 1;
    }
}


void PrintHashtable(Hashtable& H) {
    for (int i = 0; i < H.M; i++) {
        Hocsinh hs = H.table[i];
        if (hs.Maso > 0)
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "]\n";
        else
            cout << "[" << hs.Maso << ",  " << "  , " << ", " << ", " << "]\n";
    }
}
void DeleteHashtable(Hashtable& H) {
    delete[]H.table;
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
