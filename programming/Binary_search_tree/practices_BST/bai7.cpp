
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

void insertTree(Tree &T, int x) {
    if(T) {
        if(T->info > x) insertTree(T->left, x);
        if(T->info < x) insertTree(T->right, x);
    } else {
        T = get_node(x);
    }
}
void inputTree(Tree &T) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        insertTree(T, x);
    }
}
void LNR(Tree T) {
    if(T->left) LNR(T->left);
    cout << T->info << " ";
    if(T->right) LNR(T->right);
}
int isFullBinaryTree(Tree T) {
    if(!T) return 1;
    if((T->left && !T->right) || (!T->left && T->right)) {
        return false;
    }
    return isFullBinaryTree(T->left) && isFullBinaryTree(T->right);
}


int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	int i=isFullBinaryTree (T);
	if(i==0) cout<<"\nThe tree is not a Full Binary Tree";
    else cout<<"\nThe tree is a Full Binary Tree";
	return 0;
}

