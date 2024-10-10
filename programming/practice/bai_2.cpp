#include <iostream>
#include <vector>
using namespace std;

void Nhap_mang(vector <int> &a, int n) {
    while (n > 0) {
        int tmp; cin >> tmp;
        a.push_back(tmp);
        --n;
    }
}

int dem = 0;
int binary_search(vector<int> a, int l, int r, int k) {
    while (l <= r) {
        dem++;
        int mid = l + (r - l) / 2;
        if(a[mid] == k)
            return mid;
        else if(a[mid] < k)
            l = mid + 1;
        else if(a[mid] > k)
            r = mid - 1;
    }
    return -1;
}
int main() {
    vector<int> a;
    int n; cin >> n;
    Nhap_mang(a, n);
    int k; cin >> k;
    int kq = binary_search(a, 0, n - 1, k);
    cout << kq << endl;
    if(kq != -1) cout << dem;
}