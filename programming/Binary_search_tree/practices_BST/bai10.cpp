
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
        if(T->info == x) return;
        if(T->info > x) insert_node(T->left, x);
        if(T->info < x) insert_node(T->right, x);
    } else {
        T = get_node(x);
    }
}
void input_Tree(Tree &T) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; 
        insert_node(T, x);
    }
}
Node* is_floor(Tree &T, int k, Node* max) {
    if(!T) return max;
    if((T->info < k || T->info == k) && T->info > max->info) {
        max = T;
    } 
    max = is_floor(T->left, k, max);
    max = is_floor(T->right, k, max);
    return max;
}

void find_floor(Tree &T) {
    int k; cin >> k;
    Node* p = is_floor(T, k, get_node(-201));
    if(p && p->info != -201) cout << p->info;
    else cout << 201;
}

int main() {
    Tree T = nullptr;
    input_Tree(T);
    find_floor(T);
}