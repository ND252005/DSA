
#include <iostream>
using namespace std;

struct node {
    int info;
    node *left, *right;
};


node* getNode(int x){
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
        T = getNode(x);
    }
}

void replace(node *&p, node *&k) {
	if(k->left != nullptr) replace(p, k->left);
	else {
		p->info = k->info;
		node* temp = k;
		k = k->right;
		delete temp;  
	}
}

void deletee(Tree &T) {
	if(!T) return;
	node *p = T;
	if(T->right == nullptr){
		T = T->left;
		delete p;	
	} else if(T->left == nullptr) {
		T = T->right;
		delete p;
	}
	else {
		replace(T, T->right);
	}
}
void deleteRoot(Tree &T, int m) {
	for(int i = 0; i < m && T != nullptr; i++) {
		deletee(T);
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

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
	int m; cout<<"\nEnter m: ";cin>>m;
	deleteRoot(T,m);
	cout<<"\nNLR: "; NLR(T);

	return 0;
}
