
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
bool isSquare (int n);
void SearchStandFor(Node* &p, Node* &q); //Chon node phai nhat tren nhanh con ben trai
void deleteSquareNumbers(Tree &T);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"\nNLR: "; NLR(T);
    cout<<"\nDelete all square numbers:";
    deleteSquareNumbers(T);
    cout<<"\nNLR: "; NLR(T);

    return 0;
}
Node *getNode(int x) {
    Node* p = new Node();
    p->info = x;
    p->pLeft = p->pRight = nullptr;
    return p;
}
void insertNode(Tree &T, int x) {
    if(T) {
        if(T->info == x) return;
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
        if(T->pLeft) NLR(T->pLeft);
        if(T->pRight) NLR(T->pRight);
    }
}
bool isSquare(int n) {
    for(int i = 1; i <= n; i++) {
        // //debug
        // if(i * i == n) {
        //     cout << '\n' << i;
        // }
        if(i * i == n) return true;
        if(i * i > n) break;
    }
    return false;
}
void SearchStandFor(Node* &p, Node* &q) {
    if(q->pRight) {
        SearchStandFor(p, q->pRight);
    } else {
        p->info = q->info;
        Node* temp = q;
        q = q->pLeft;
        delete temp;
    }
}
void deleteSquareNumbers(Tree &T) {
    if(!T) return;
    if(isSquare(T->info)) {
        if(T->pLeft) SearchStandFor(T, T->pLeft);
        else {
            if(T->pRight) {
                Node* temp = T;
                T = T->pRight;
                delete temp;
            } else {
                delete T;
                T = nullptr;
            }
        }
    }
    if(T) deleteSquareNumbers(T->pLeft);
    if(T) deleteSquareNumbers(T->pRight);
}
