
#include <iostream>
using namespace std;


void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

void MergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void inputArray(int *a, int n){
    for(int i = 0; i < n; i++){
        cin >> a[i]; 
    }
}
void outputArray(int *a, int n){
    for(int i; i < n; i++){
        cout << a[i] << ' ';
    }
}

int binarySearch(int *a,int n, int low, int high, int x){
    while(low <= high){
        int mid = low + (high - low)/2;
        if (a[mid] == x)
            return mid;
        if (a[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n; cin>>n;
    int *a = new int[n];
    inputArray(a,n);
    MergeSort(a,0,n-1);
    cout<<"Sorted Array: ";
    outputArray(a,n);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x; cin>>x;
    cout<<x<<endl;
    int result = binarySearch(a,n,0,n-1,x);
    if (result ==-1) cout<<x<<" is not found";
    else cout<<x<<" is found at the position " << result;

	return 0;
}

