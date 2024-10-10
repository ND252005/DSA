#include <iostream>
using namespace std;
long long dem = 0;

void inputArray(long long *&a, long long &n) {
	a=new long long[n];
	cin>>n;
	for(long long i=0;i<n;i++)
		cin>>a[i];
}
void outputArray(long long *a, long long n) {
	cout << "Sorted Array: ";
	for(long long i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout << endl;
	cout << "Number of times to swap 2 numbers: " << dem << endl;
}
//Phan hoach lomuto
void quick_sort_lomuto(long long *&a, long long l, long long r) {
	long long pivot = a[r];
	long long i = -1; long long j = 0;
	while(j <= r) {
		if(a[j] <= pivot){
			i++;
			swap(a[i], a[j]);
		}
		j++;
	}
	if(i - 1 > 0) {
		quick_sort_lomuto(a, 0, i - 1);		
	}
	if(i + 1 < r) {
		quick_sort_lomuto(a, i + 1, r);		
	}
}

//Phan hoach hooare
void quick_sort(long long *&a, long long l, long long r) {
	if(l >= r) return;
	long long x = a[(l + r) /2];
	// //debug
	// cout << x << endl;
	long long i = l; long long j = r;
	while(i <= j) {
		while(a[i] > x) i++;
		while(a[j] < x) j--;
		if(i <= j) {
			//debug 
			// cout << a[i] << '\t' << a[j] << endl;
			swap(a[i], a[j]);
			dem++;
			i++; j--;
		}
	}
	if(l < j) quick_sort(a, l, j);
	if(i < r) quick_sort(a, i, r);
}

int main() {
   long long *a=NULL, n;
   inputArray(a,n);
   quick_sort(a, 0, n - 1);
   outputArray(a,n);
   delete [] a;
   return 0;
}