#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Nhap_ds(vector <int> &a) {
    int tmp;
    cout << "Nhap danh sach : " << endl;
    cin >> tmp;
    while(tmp > 0){
        a.push_back(tmp);
        cin >> tmp;
    }
}

void Xuat_ds(vector <int> a) {
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    vector<int>::iterator it;
    for(it = a.begin(); it != a.end(); ++it){
        cout << *it << ' ';
    }
}

void Top5(vector <int> a) {
    if(a.size() < 5){
        cout << "khong du 5 phan tu " << endl;
        return;
    }

    sort(a.begin(), a.end());
    for(int i = a.size() - 1; i > a.size() - 6; i--)
        cout << a[i] << ' ';
    cout << endl;
}

int Tim_k(vector <int> a, int k) {
    vector<int> :: iterator it;
    it = find(a.begin(),a.end(), k );
    if(it != a.end())
        return it - a.begin();
    return -1;
}
int main() {
    vector <int> a;
    Nhap_ds(a);
    Xuat_ds(a);
    cout << endl;
    Top5(a);
    cout << "Nhap so k can tim: "; 
    int k; cin >> k;
    if(k != -1)
        cout << Tim_k(a, k);
    else cout << "khong tim thay k";
}