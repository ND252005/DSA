//template
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
    cin >> x.Gioitinh;
    cin >> x.Namsinh;
    cin >> x.TBK;
}
//code here 
void CreateHashtable(Hashtable &H, int m) {
    H.M = m;
    H.n = 0;
    H.table = new Hocsinh[m];
    for(int i = 0; i < m; i++) {
        H.table[i].Maso = 0;
    }
}
int Search(Hashtable &H, int k, int &nprob) {
    for (int i = 0; i < H.M; i++) {
        int key = ((k % H.M) + i * i) % H.M;
        if (H.table[key].Maso == k) {
            nprob = i;
            return key;
        }
        if (H.table[key].Maso == EMPTY ) {
            break;
        }
    }
    return -1;
}

void DeleteHashtable(Hashtable &H) {
    delete [] H.table;
    H.table = nullptr;
    H.M = 0;
    H.n = 0;
}
//template
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
        if (Search(hashtable, k, nprob) >- 1) {
            cout << "THAM DO " << nprob << endl;
        }
        else {
            cout << "KHONG TIM THAY" << endl;
        }
    }
    DeleteHashtable(hashtable);
    return 0;
}
