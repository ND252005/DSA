#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *left, *right;
};
typedef struct Node* Tree;
Node* get_node(int x) {
    Node* p = new Node();
    p->info = x;
    p->left = p->right = nullptr;
    return p;
}

void insert_node(Tree &T, int x) {
    if(T) {
        if(T->info > x) insert_node(T->left, x);
        if(T->info < x) insert_node(T->right, x);
    } else {
        T = get_node(x);
    }
}
void input_tree(Tree &T) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        insert_node(T, x);
    }
}
int Search(Tree T, int x) {
    if(!T) return 0;
    if(T->info == x) return 1;
    if(T->info > x) return Search(T->left, x);
    return Search(T->right, x);
}
void path(Tree T, int x) {
    if(T) {
        cout << T->info << " ";
        if(T->info == x) return;
        if(T->info > x) path(T->left, x);
        if(T->info < x) path(T->right, x);
    } else return;
}
int main() {
    Tree T = nullptr;
    input_tree(T);
    int k; cin >> k;
    if(Search(T, k)) {
        cout << "Found. Path: ";
        path(T, k);
    } else cout << "Not found";
    return 0;
}