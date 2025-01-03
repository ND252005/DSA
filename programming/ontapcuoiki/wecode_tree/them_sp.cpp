#include <iostream>
using namespace std;

typedef struct Poduct {
    int id;
    string name;
    string type; 
    int year;
    int warranty;
}PRO;
struct Node {
    PRO info;
    Node *left;
    Node *right; 
};
typedef struct Node* Tree;

Node *get_node(PRO x) {
    Node* p = new Node();
    p->info = x;
    p->left = p-> right = nullptr;
    return p;
}
void insert_node(Tree &T, PRO x) {
    if(T) {
        if(T->info.id > x.id) insert_node(T->left, x);
        if(T->info.id < x.id) insert_node(T->right, x);
    } else {
        T = get_node(x);
    }
}
void inputTree(Tree &T) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        PRO x; 
        cin >> x.id;
        getline(cin >> ws, x.name);
        getline(cin >> ws, x.type);
        cin >> x.year; 
        cin >> x.warranty;
        insert_node(T, x);
    }
}
//NLR
void listProduct(Tree &T, string type) {
    if(T) {
        if(T->info.type == type) {
            cout << "\n" << T->info.id << "\t" << T->info.name << "\t";
            cout << T->info.type << "\t" << T->info.year << "\t" << T->info.warranty << "\n";
        }
        listProduct(T->left, type);
        listProduct(T->right, type);
    }

}
int count = 0;
int countProduct(Tree &T, int warrant) {
    if(T) {
        if(T->info.warranty > warrant) count++;
        countProduct(T->left, warrant);
        countProduct(T->right, warrant);
    }
    return count;
}


int main()
{
    Tree T = NULL;
    inputTree(T);

    string type;  cin.ignore(); getline(cin,type);
    cout<<"List of products whose type is  "<<type<<": ";
    cout<<"\nID\tName\tType\tYear\tWarranty\n";
    listProduct(T,type);

    int year;cin>>year;
    cout<<"Number of products with more than "<<year<<" years of warranty: "<<countProduct(T,year)<<endl;


	return 0;
}