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
void CreateHashtable(Hashtable &H, int m) {
    H.M = m;
    H.n = 0;
    H.table = new Hocsinh[m];
    for(int i = 0; i < m; i++) {
        H.table[i].Maso = EMPTY;
    }
}
void Input(Hocsinh &hs) {
    cin >> hs.Maso;
    getline(cin >> ws, hs.Hoten);
    cin >> hs.Gioitinh;
    cin >> hs.Namsinh;
    cin >> hs.TBK;
}
int Hashing(Hashtable &H, int i, int maso) {
    return ((maso % H.M) + i * i) % H.M;
}
int Delete(Hashtable &H, int k, int &nprob) {
    for(int i = 0; i < H.M; i++) {
        int index = Hashing(H, i, k);
        nprob = i;
        if(H.table[index].Maso == EMPTY) break;
        if(H.table[index].Maso == k) {
            H.table[index].Maso = DELETE;
            H.n--;
            return 1;
        }
    }
    return 0;
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

    int m, n, k, nprob;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    for (int i = 0; i < m; i++) {
        Input(hs);
        hashtable.table[i] = hs;
        if (hs.Maso > 0)
            hashtable.n++;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (Delete(hashtable, k, nprob)) {
            cout << "THAM DO " << nprob << endl;
        }
        else {
            cout << "KHONG XOA DUOC" << endl;
        }
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}
