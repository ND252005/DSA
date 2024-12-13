
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
void print_node_at_level(Tree &T, int k, int level) {
	if(T == nullptr) return;
	if(level == k) {
		cout << T->info << " ";
		return;
	}
	print_node_at_level(T->right, k, level + 1);
	print_node_at_level(T->left, k, level + 1);
}
void nodesWithLevel(Tree &T, int k) {
	print_node_at_level(T, k, 0);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
    int k; cout<<"Enter k: "; cin >>k;
    cout<<"\nList of nodes with level "<<k<<" (R->L) : ";
    nodesWithLevel(T, k);

	return 0;
}
