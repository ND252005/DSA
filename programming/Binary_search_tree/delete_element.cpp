
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

void replace(node *&p, node *&k) {
	if(k->left != nullptr) replace(p, k->left);
	else {
		p->info = k->info;
		node* temp = k;
		k = k->right;
		delete temp;  
	}
}
node* Search(Tree &T, int x) {
    if (!T || T->info == x) return T;
    node* p = Search(T->left, x);
    if (p) return p;
    return Search(T->right, x);
}

void deleteNode(Tree &T, int x) {
	if(!T) return;
	if(x < T->info) deleteNode(T->left, x);
	else if(x > T->info) deleteNode(T->right, x);
	else {
		if(T->left && T->right) {
			node *temp = T->right;
			while(temp->left) temp = temp ->left;
            T->info = temp->info;
            deleteNode(T->right, temp->info);
		} else {
			node *temp = T;
			if(T->left == nullptr) {
				T = T->right;
			} else {
				T = T->left;
			}
			delete temp;
		}
	}
}

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
    int x; cout<<"\nEnter the element you want to delete: ";cin>>x;
    deleteNode(T,x);
    cout<<"\nNLR: "; NLR(T);

	return 0;
}
