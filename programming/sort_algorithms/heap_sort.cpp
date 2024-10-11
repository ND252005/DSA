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

void heapify(int *&a, int N, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if(l < N and a[l] > a[largest])
		largest = l;
	if(r < N and a[r] > a[largest])
		largest = r;
	if(largest != i) {
		swap(a[i], a[largest]);
		heapify(a, N, largest);
	}
}

void heap_sort(int *&a, int N) {
	for(int i = N /2 - 1; i >= 0; i--) {
		heapify(a, N, i);
	}
	for(int i = N - 1; i > 0; i--) {
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

int main() {
   int *a=NULL, n;
	inputArray(a, n);
	heap_sort(a, n);
	outputArray(a, n);
	return 0;
}