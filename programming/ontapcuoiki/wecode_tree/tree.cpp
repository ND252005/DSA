#include <iostream>
#include <stack>
#include <queue>
using namespace std;


struct Node {
    int info;
    Node *left, *right;
};

typedef Node* Tree;
Node* get_node(int x) {
    Node* p = new Node();
    p->info = x;
    p->left = p->right = nullptr;
    return p;
}

void insert(Tree &T, int x) {
    if(T) {
        if(T->info == x) return;
        if(T->info > x) insert(T->left, x);
        if(T->info < x) insert(T->right, x);
    } else {
        T = get_node(x);
    }
}

//duyet LRN de quy
void LRN1(Tree T) {
    if(T) {
        LRN1(T->left);
        LRN1(T->right);
        cout << T->info<< " ";
    }
}
//duyet LRN khong de quy
void LRN2(Tree T) {
    stack<Node*> s1, s2;
    s1.push(T);
    while(T != nullptr && !s1.empty()) {
        Node* current = s1.top();
        s1.pop();
        s2.push(current);
        if(current->left) s1.push(current->left);
        if(current->right) s1.push(current->right);
    }
    while(!s2.empty()) {
        cout << s2.top()->info << " ";
        s2.pop();
    }
}

//duyet NLR dung de quy
void NLR1(Tree T) {
    if(T) {
        cout << T->info << " ";
        NLR1(T->left);
        NLR1(T->right);
    }
}

//duyet NLR khong de quy
void NLR2(Tree T) {
    if(!T) return;
    stack<Node*> s;
    s.push(T);
    while(!s.empty()) {
        Node* current = s.top();
        cout << current->info << " ";
        s.pop();
        if(current->right) s.push(current->right);
        if(current->left) s.push(current->left);
    } 
}

//duyet LNR dung de quy
void LNR1(Tree T) {
    if(T) {
        LNR1(T->left);
        cout << T->info << " ";
        LNR1(T->right);
    }
}

//duyet LNR khong de quy
void LNR2(Tree T) {
    if(!T) return;
    stack <Node *> s;
    Node *current = T;
    while(current != nullptr || !s.empty()) {
        while(current != nullptr) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->info << " ";
        current = current ->right;
    }
}

//in cay theo chieu rong
void BFS(Tree T) {
    if(!T) return;
    queue <Node *> q;
    q.push(T);
    while(!q.empty()) {
        Node *current = q.front();
        q.pop();
        cout << current->info <<" ";
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    }
}
//in cay theo chieu sau 


int main() {
    Tree T = nullptr;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(T, x);
    }

    cout << "LRN dung  de quy: "; LRN1(T); cout << endl;
    cout << "LRN khong de quy: "; LRN2(T); cout << endl;

    cout << "\nNLR dung  de quy: "; NLR1(T); cout << endl;
    cout << "NLR khong de quy: "; NLR2(T); cout << endl;

    cout << "\nLNR dung  de quy: "; LNR1(T); cout << endl;
    cout << "LNR khong de quy: "; LNR2(T); cout << endl;

    cout << "BFS: "; BFS(T); cout << endl;

}

