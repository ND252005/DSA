#include <iostream>
#include <vector>
using namespace std;

void Nhap_mang(vector <int> &a, int &n) {
    while (n > 0) {
        int tmp; cin >> tmp;
        a.push_back(tmp);
        --n;
    }
}
void Xuat_ds(vector <int> a) {
    cout << "Mang vua nhap:" << endl;
    vector<int>:: iterator it;
    for(it = a.begin(); it != a.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
    int first, last;
    int index_first, index_last, even_max;
    bool check = 0;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] % 2 == 0){
            first = a[i];
            index_first = i;
            check = !check;
            break;
        }
   }
    if(check){
        for(int i = a.size() - 1; i > 0; --i) {
            if(a[i] % 2 == 0){
                last = a[i];
                index_last = i;
                break;
            }
        }
        even_max = first;
        for(int i = index_first + 1; i <= index_last; ++i){
            if(a[i] % 2 == 0 && a[i] > even_max) {
                even_max = a[i];
            }
        }
    }
    if(check) {
        cout <<  first << " la so chan dau tien, co chi so " << index_first << " trong mang" << endl;
        cout <<  last << " la so chan cuoi cung, co chi so " << index_last << " trong mang" << endl;
        cout << "So chan lon nhat: " << even_max << endl;
    } else {
        cout << "Mang khong co so chan" << endl;
    }
    
}
int main () {
    vector <int> a;
    int n; cin >> n;
    Nhap_mang(a, n);
    Xuat_ds(a);
}