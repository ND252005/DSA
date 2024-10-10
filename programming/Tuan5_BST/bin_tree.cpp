#include <iostream>
using namespace std;
struct node {
    int info;
    node *left, *right;
};
// struct Tree {
//     node *root;
// };

node* get_node(int x){
    node* p = new node;
    p->info = x;
    p->left = p->right = nullptr;
    return p;
}

typedef node* Tree;
void insert(Tree T, int x) {
    if(T) {
    if(T->info == x)
        return;
    if(T->info > x)
        insert(T->left, x);
    if(T->info < x)
        insert(T->right, x);
    } else {
        //khi di den vi tri can them

    }
}

void NLR(Tree T) {
    if(T){
        cout << T->info;
        NLR(T->left);
        NLR(T->right);
    } else {
        return;
    }
}

int main(){
    Tree T = nullptr;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(T, x);
    }

}