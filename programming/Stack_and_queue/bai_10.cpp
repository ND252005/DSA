#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n;
    int *a = new int[n];
    
    // Nhập mảng
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int dem = 0; // Biến đếm

    // Kiểm tra nếu n >= 2 (vì nếu n <= 1, thì không cần đếm)
    if(n > 1){
        for(int i = 0; i < n - 1; i++) {
            // Nếu phần tử trước lớn hơn phần tử sau
            if(a[i] > a[i+1]){
                int k = 2;
                dem++;  // Đếm phần tử đầu tiên vi phạm
                // Tiếp tục kiểm tra các phần tử tiếp theo
                while(i + k < n && a[i + 1] <= a[i + k]){
                    dem++;  // Đếm các phần tử vi phạm tiếp theo
                    k++;
                }
            }
        }
    }
    
    // Xuất kết quả
    cout << dem;

    // Giải phóng bộ nhớ
    delete[] a;

    return 0;
}
