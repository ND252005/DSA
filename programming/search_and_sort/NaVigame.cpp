#include <iostream>
#include <vector>
using namespace std;

// array, pos min, pos max, item, mode search = 1 or insert = 0  
int binary_search(const vector<long long>& arr, int low, int high, long long x, int mode) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Mode 0: Tìm vị trí để chèn
        if (mode == 0) {
            if (arr[mid] == x) 
                return -1;  // Trả về -1 nếu đã có phần tử
            else if (arr[mid] > x) 
                high = mid - 1;
            else 
                low = mid + 1;
        } 
        // Mode 1: Tìm kiếm phần tử x
        else if (mode == 1) {
            if (arr[mid] == x) 
                return mid + 1;  // Trả về chỉ số 1-based
            else if (arr[mid] > x) 
                high = mid - 1;
            else 
                low = mid + 1;
        }
    }

    if (mode == 0) return low;  // Trả về vị trí cần chèn
    return 0;  // Trả về 0 nếu không tìm thấy phần tử trong mode 1
}

void insertion_sort(vector<long long>& arr, long long b) {
    int pos = binary_search(arr, 0, arr.size() - 1, b, 0);
    
    if (pos != -1) {  // Chỉ chèn nếu phần tử chưa tồn tại
        arr.insert(arr.begin() + pos, b);
    }
}

int main() {
    vector<long long> arr;
    vector<long long> output;
    int a;
    long long b;
    cin >> a >> b;
    while (a != 0) {
        if (a == 1) {
            insertion_sort(arr, b);  // Chèn phần tử
        }
        else if (a == 2) {
            output.push_back(binary_search(arr, 0, arr.size() - 1, b, 1));  // Tìm kiếm phần tử
        }

        cin >> a;
        if(a != 0) cin >> b;
        else break;
    }

    for (auto i : output) {
        cout << i << endl;
    }

    return 0;
}
