
#include <iostream>
using namespace std;

/*Cach 1: Khi da cai dat List roi, dinh nghia Stack dua tren List
struct Stack
{
	List L;
};

Cach 2: Cai dat lai Stack tu dau, giong nhu List
struct node
{
    int info;
    node *next;
};
struct Stack
{
    node *pHead; // pTail khong co cung duoc

};*/

struct node {
    int info;
    node *next;
};

struct Stack {
    node *pHead;
};

void Init(Stack &S) {
    S.pHead = nullptr;
}

node* get_node(int x) {
    node*p = new node;
    p->info = x;
    p->next = nullptr;
    return p;
}

bool isEmpty(Stack S) {
    if(!S.pHead)
        return true;
    return false;
}

void Push(Stack &S, int x) {
    node *p = get_node(x);
    if(isEmpty(S))
        S.pHead = p;
    else {
        p->next = S.pHead;
        S.pHead = p; 
    }
}

void Pop(Stack &S) {
    if(isEmpty(S))
        return;
    else {
        if(!S.pHead->next){
            S.pHead = nullptr;
        } else {
            node *p = S.pHead;
            S.pHead = S.pHead->next;
            p = nullptr;
        }
    } 
}
void DecimaltoBinary1(int n, Stack &S) {
    if(n == 0) {
        Push(S, 0);
        return;
    }
    while(n != 0) {
        Push(S, n % 2);
        n /= 2;
    }
}
void printStack(Stack &S) {
    if(isEmpty(S))
        cout << "Stack is empty";
    else{
        node *p = S.pHead;
        while(p){
            cout << p->info;
            p = p->next;
        }
    }
}


int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary1(n,S);
    printStack(S);
    return 0;
}

