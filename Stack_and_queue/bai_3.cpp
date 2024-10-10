
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n; // so luong phan tu cua stack
};

void Init(Stack &S) {
    S.n = 0;
}

void Push(Stack &S, int x) {
    S.arr[S.n] = x;
    S.n++;
}

bool isEmpty(Stack S) {
    if(S.n == 0)
        return true;
    return false; 
}

void printStack(Stack S) {
    if(isEmpty(S))
        cout << "Stack is empty";
    else
        for(int i = 0; i < S.n; i++) {
            cout << S.arr[S.n - i - 1];
        }
}

int Top(Stack S) {
    if(isEmpty(S))
        return -1;
    return S.arr[S.n - 1];
}

void Pop(Stack &S) {
    S.n--;
}
void DecimaltoBinary2(int n, Stack &S) {
    if(n == 0){
        Push(S, 0);
        return;
    }
    while (n != 0){
        Push(S, n % 2);
        n /= 2;
    }
}


int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary2(n,S);
    printStack(S);
    return 0;
}
