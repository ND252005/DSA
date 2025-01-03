#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *pLeft;
    Node *pRight;
};
typedef struct Node* Tree;
Node *getNode(int x);
void insertNode(Tree & T, int x);
void inputTree(Tree &T);
void NLR(Tree T);
int nodesWithLevel(Tree T, int k, int c);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"\nNLR: "; NLR(T);
    int k; cout<<"\nEnter k: "; cin >>k;
    cout<<nodesWithLevel(T,k,0); //neu tham so thu 3 khong can dung thi trong ham khong can xu ly

    return 0;
}
//###INSERT CODE HERE -
Node *getNode(int x) {
    Node* p = new Node();
    p->info = x;
    p->pLeft = p->pRight = nullptr;
    return p;
}
void insertNode(Tree &T, int x) {
    if(T) {
        if(T->info > x) insertNode(T->pLeft, x);
        if(T->info < x) insertNode(T->pRight, x);
    } else {
        T = getNode(x);
    }
}
void inputTree(Tree &T) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; 
        insertNode(T, x);
    }
}
void NLR(Tree T) {
    if(T) {
        cout << T->info << " ";
        NLR(T->pLeft);
        NLR(T->pRight);
    } else {
        return;
    }
} 
bool check = true;
int h;
int nodesWithLevel(Tree T, int k, int c) {
    if(check) {
        cout << "List of nodes with level" << k << " (R->L): ";
        h = k;
        check = false;
    }
    // if(k == 0) {
    //     cout << T->info << " "; 
    //     cout <<  "\nNumber of nodes with level " << k << ": ";
    //     return 1;
    // }
    if(T == nullptr) {
        return 0;
    }
    if(k == 0) {
        cout << T->info << " ";
        return 1;
    }
    int cnt = 0;
    cnt += nodesWithLevel(T->pRight, k - 1, c);
    cnt += nodesWithLevel(T->pLeft, k - 1, c);
    if(k == h) {
        cout << "\nNumber of nodes with level " << k << ": ";
    }

    return cnt;
}