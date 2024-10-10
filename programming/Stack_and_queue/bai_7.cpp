#include <iostream>
#include <stack>
using namespace std;



int main(){
    int n; cin >> n;
    stack <int> S;
    if(n == 0){
        cout << "0";
    }
    while(n != 0){
        S.push(n%2);
        n /= 2;
    }
    while(!S.empty()){
        cout << S.top();
        S.pop();
    }

}