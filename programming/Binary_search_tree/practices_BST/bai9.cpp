
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
        if(T->info == x) return;
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
void SearchStandFor(Node* &p, Node* &q) {
    if(q->right) {
        SearchStandFor(p, q->right);
    } else {
        p->info = q->info;
        Node* temp = q;
        q = q->left;
        delete temp;
    }
}
Node* is_max(Tree &T, Node* max = nullptr) {
    if(!T) return max;
    if(max == nullptr || T->info > max->info) max = T;
    max = is_max(T->left, max);
    max = is_max(T->right, max);
    return max;
}
Node* is_second_max(Tree &T, Node* max = nullptr, Node* second = nullptr) {
    if(!T) return second;
    if(T != max && (second == nullptr || T->info > second->info)) second = T;
    second = is_second_max(T->left, max, second);
    second = is_second_max(T->right, max, second);
    return second;
}
void secondLargest(Tree &T) {
    Node* second = is_second_max(T, is_max(T));
    if(second) {
        cout << "2nd largest value is " << second->info;
    }
}


int main()
{
	Tree T = NULL;
	inputTree(T);
    secondLargest(T);
	return 0;
}
