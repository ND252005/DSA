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

int countNodes(Tree T) {
    if(!T) return 0;
    return 1 + countNodes(T->left) + countNodes(T->right);
}

int depthOfTree(Tree T) {
    if(!T) return -1;
    return 1 + max(depthOfTree(T->left), depthOfTree(T->right));
}

void countEven(Tree T, int &count_even) {
    if(!T) return;
    if(!(T->info %2))
        count_even++;
    countEven(T->left, count_even);
    countEven(T->right, count_even);
}

void countOdd(Tree T, int &count_odd) {
    if(!T) return;
    if((T->info %2))
        count_odd++;
    countOdd(T->left, count_odd);
    countOdd(T->right, count_odd);
}

int countPositive(Tree T) {
    if(!T) return 0;
    if(T->info > 0)
        return 1 + countPositive(T->left) + countPositive(T->right);
    return countPositive(T->left) + countPositive(T->right);
}
int countNegative(Tree T) {
    if(!T) return 0;
    if(T->info < 0)
        return 1 + countNegative(T->left) + countNegative(T->right);
    return countNegative(T->left) + countNegative(T->right);
}

bool isPrime(int x) {
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}
int countPrime(Tree T) {
    if(!T) return 0;
    if(isPrime(T->info))
        return 1 + countPrime(T->left) + countPrime(T->right);
    return countPrime(T->left) + countPrime(T->right);
}
void listPrime(Tree T) {
    if(T) {
        if(isPrime(T->info)) {
            cout << T->info << " ";
        }
        listPrime(T->left);
        listPrime(T->right);
    }
}


int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<"LNR: "; LNR(T); cout<<endl;

	cout<<"Number of nodes: " << countNodes(T)<<endl;
    cout<<"Depth of Tree: "<<depthOfTree(T)<<endl;

    int count_even = 0, count_odd =0;
    countEven(T, count_even);countOdd(T, count_odd);
    cout<<"Number of even nodes: "<<count_even<<endl;
    cout<<"Number of odd nodes: "<<count_odd<<endl;

    cout<<"Number of positive nodes: "<<countPositive(T)<<endl;
    cout<<"Number of negative nodes: "<<countNegative(T)<<endl;

    cout<<"Number of prime nodes: "<<countPrime(T)<<endl;
    cout<<"Prime numbers: "; listPrime(T);

	return 0;
}
