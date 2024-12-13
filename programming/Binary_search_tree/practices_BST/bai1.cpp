#include <iostream>
using namespace std;
struct node {
    int info;
    node *left, *right;
};
typedef node* Tree;
node* get_node(int x) {
    node *p = new node;
    p->info = x;
    p->left = p->right = nullptr;
    return p;
}

bool check = false;
void insert(Tree &T, int x) {
    if(T) {
        if(T->info == x) { check = true; return; }
        if(T->info > x) insert(T->left, x);
        if(T->info < x) insert(T->right, x);
    } else {
        T = get_node(x);
    }
}

void inputTree(Tree &T) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(T, x);
        if(check == true) {
            cout << "Bi trung gia tri, ket thuc qua trinh tao cay" << endl;
            break;
        }
    }
}
void NLR(Tree &T) {
    if(T) {
        cout << T->info << " ";
        if(T->left) NLR(T->left);
        if(T->right) NLR(T->right);
    }
}



int main()
{
	Tree T = NULL;
	inputTree(T); //Khi bi trung gia tri thi ket thuc qua trinh tao cay, khong nhap tiep nua
	cout<<"NLR: "; NLR(T);
	return 0;
}



