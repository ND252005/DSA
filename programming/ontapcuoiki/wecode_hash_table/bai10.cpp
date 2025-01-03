
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;


vector<int> get_ans(const vector<int>& A,int K){
	map<int,int> Hash;
    for(int i = 0; i < A.size(); i++) {
        Hash[A[i]] = 0;
    }
    for(int i = 0; i < A.size(); i++) {
        Hash[A[i]]++;
    }
    vector<int> key;
    for(auto x : Hash) {
        key.push_back(x.first);
    }
    for(int i = 1; i < key.size(); i++) {
        int x = Hash[key[i]]; int j;
        for(j = i - 1; j >= 0 &&x < Hash[key[j]]; j--) {
            key[j+1] =key[j];
        }
        key[j+1] = x;
    }
    vector<int> ans;
    int i = 0;
    while(k != 0) {
        if(Hash[key[i]] == 0) {
            i++;
        } else {
            Hash[key[i]]--;
            ans.push_back(key[i]);
        }
        k--;
    }
    return ans;


	
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n >> k;
	
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> ans = get_ans(a,k);
	
	for (const int& x: ans) cout << x << ' ';
	return 0;
}
