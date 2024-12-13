#include <iostream>
#include <set>
#include <vector>
using namespace std;



int main() {
	vector<int> a;
	set<int> st;
	int n; cin >> n;
	int m; cin >> m;
	for(int i = 0; i < m; i++) {
		int k; cin >> k;
		st.insert(k);
		a.push_back(k);
	}

	for(int i = 0; i < m; i++) {
		if(i < m) {
			cout << a[m - i - 1] << ' ';
		}
	}
	for(int i = 1; i <= n; i++) {
		if (st.find(i) != st.end()) {
			cout << i << ' ';
		}
	}
	return 0;
}