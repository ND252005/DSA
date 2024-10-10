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
void insert(Tree &T, int x) {
    if(T) {
    if(T->info == x)
        return;
    if(T->info > x)
        insert(T->left, x);
    if(T->info < x)
        insert(T->right, x);
    } else {
        //khi di den vi tri can them
        T = get_node(x);
    }
}

void inputTree(Tree &T){
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(T, x);
    }
}

void NLR(Tree T) {
    if(T){
        cout << T->info << " ";
        NLR(T->left);
        NLR(T->right);
    } else {
        return;
    }
}

void LRN(Tree T){
    if(T) {
        LRN(T->left);
        LRN(T->right);
        cout << T-> info << " ";
    } else {
        return;
    }
}

void LNR(Tree T){
    if(T) {
        LNR(T->left);
        cout << T-> info << " ";
        LNR(T->right);
    } else {
        return;
    }
}



int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	return 0;
}
