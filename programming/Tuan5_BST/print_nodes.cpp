
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

void listLeafs(Tree T) {
    if (T) {
        // Nếu cả cây con trái và cây con phải đều là nullptr thì đó là node lá
        if (!T->left && !T->right) {
            cout << T->info << " ";  // Xuất giá trị của node lá
        }
        // Duyệt tiếp cây con trái và cây con phải
        listLeafs(T->left);
        listLeafs(T->right);
    }
}
void listNodesWithOneChild(Tree T) {
    if (T != NULL) {
        if ((T->left == NULL && T->right != NULL) || (T->left != NULL && T->right == NULL)) {
            cout << T->info<< " ";
        }
        listNodesWithOneChild(T->left);
        listNodesWithOneChild(T->right);
    }
}
void listNodesWithTwoChildren(Tree T) {
    if (T) {
        // Nếu cả cây con trái và cây con phải đều là nullptr thì đó là node lá
        if (T->left && T->right) {
            cout << T->info << " ";  // Xuất giá trị của node lá
        }
        // Duyệt tiếp cây con trái và cây con phải
        listNodesWithTwoChildren(T->left);
        listNodesWithTwoChildren(T->right);
    }
}

void listInternalNodes(Tree T, int val) {
	if(T == NULL)		
		return;
		
	if(val != 0)
		if(T->left != NULL || T->right != NULL)
			cout << T->info << " ";
		
	if(T->left) listInternalNodes(T->left, 1);
	if(T->right) listInternalNodes(T->right, 1);
    
}


int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	cout<<"\nLeaf nodes: "; listLeafs(T);
	cout<<"\nInternal nodes: "; listInternalNodes(T,0); //co de san tham so thu 2 cho ai co nhu cau dung, SV khong dung tham so thu 2 nay cung khong sao
	cout<<"\nNodes with one child: "; listNodesWithOneChild(T);
	cout<<"\nNodes with two children: "; listNodesWithTwoChildren(T);

	return 0;
}
