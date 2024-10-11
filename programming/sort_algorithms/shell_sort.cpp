#include <iostream>
using namespace std;
void inputArray(int *&a, int &n) {
	a=new int[n];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
}

void outputArray(int *a, int n) {
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout << endl;
}
void shell_sort(int *&a, int n){
	int interval, i, j, temp;
	for(interval = n/2; interval > 0; interval /= 2){
		for(i = interval; i < n; i++){
			temp = a[i];
			for(j = i; j >= interval && a[j - interval] > temp; j -= interval){
				a[j] = a[j - interval];				
			}
			a[j] = temp;
		}
    }
}
int main() {
   int *a=NULL, n;
	inputArray(a, n);
	shell_sort(a, n);
	outputArray(a, n);
	return 0;
}