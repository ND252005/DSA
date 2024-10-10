#include <iostream>
using namespace std;

struct Point {
    double x, y, z;
};

bool operator<(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.z < b.z;
}

bool operator==(const Point& a, const Point& b) {
    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}

int binarySearch(Point* A, int n, const Point& p) {
    int left = 0, right = n - 1;
    int steps = 0;

    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;

        if (A[mid] == p) {
            return steps;
        }
        if (A[mid] < p) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    Point* A = new Point[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i].x >> A[i].y >> A[i].z;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        Point p;
        cin >> p.x >> p.y >> p.z;

        int result = binarySearch(A, n, p);
        if (result == -1) {
            cout << "KHONG" << endl;
        } else {
            cout << result << endl;
        }
    }

    delete[] A;
    return 0;
}
