/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

//###INSERT CODE HERE -
int binary_search_greatestLesser_last_occurrence(int a[], int n, int x) {
    int l = 0, r = n - 1;
    int res = -1; // Kết quả mặc định nếu không có phần tử thỏa mãn
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] < x) {
            res = m;  // Cập nhật kết quả là chỉ số của phần tử này
            l = m + 1; // Tìm kiếm ở nửa phải
        } else {
            r = m - 1; // Tìm kiếm ở nửa trái
        }
    }
    return res; // Trả về chỉ số của phần tử cuối cùng nhỏ hơn x
}

int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_greatestLesser_last_occurrence(a, n, x);

    return 0;
}