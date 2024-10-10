
#include <iostream>
using namespace std;
struct Node {
    int info;
    Node *left, *right;
};
// struct Tree {
//     node *root;
// };

Node* get_node(int x){
    Node* p = new Node;
    p->info = x;
    p->left = p->right = nullptr;
    return p;
}

typedef Node* Tree;
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
void LNR(Tree T){
    if(T) {
        LNR(T->left);
        cout << T-> info << " ";
        LNR(T->right);
    } else {
        return;
    }
}

Tree Search(Tree T, int x){
    if(T){
        if(x != T->info){
            if(x < T->info) return Search(T->left, x);
            else if(x > T->info) return Search(T->right, x);
        } else {
            return T;
        }
    }
    return nullptr;

}
int minValue(Tree T) {
    if(T) {
        if(T->left) return minValue(T->left);
    }
    return T->info;
}
int maxValue(Tree T) {
    if(T) {
        if(T->right) return maxValue(T->right);
    }
    return T->info;
}





int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T); cout<<endl;


    int x; cout<<"\nEnter the element you want to find: ";cin>>x;
    Node *p=Search(T,x);
    if (p) cout<< "Found";
    else cout<<"Not found";
    cout<<"\nMinimum value in BTS is "<<minValue(T);
    cout<<"\nMinimax value in BTS is "<<maxValue(T);


	return 0;
}

