
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct node
{
    int info;
    node *left, *right;
};
typedef node* Tree;
node* getNode(int x)
{
    node* p =new node;
    p->info=x;
    p->left=p->right=NULL;
    return p;
}
void insertTree(Tree &T, int x)
{
    if(!T) T=getNode(x);
    else
    {
        if(T->info==x) return;
        if(x<T->info) insertTree(T->left,x);
        else insertTree(T->right, x);
    }

}
void inputTree(Tree &T)
{
    int n,x; cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insertTree(T, x);
    }
}
void LRN(Tree T)
{
    if (T == nullptr) return;

    stack<node*> s1, s2;
    s1.push(T);

    while(!s1.empty()) {
        node* current = s1.top();
        s1.pop();
        s2.push(current);
        if(current->left) s1.push(current->left);
        if(current->right) s1.push(current->right);
    }
    while(!s2.empty()) {
        cout << s2.top()->info << ' ';
        s2.pop(); 
    }

}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nLRN: "; LRN(T);
	return 0;
}
