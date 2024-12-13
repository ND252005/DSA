
#include <iostream>
#include <string>
using namespace std;


typedef struct Product {
    int id;
    string name;
    string type;
    int year;
    int warranty;
} PRO ;

struct node {
    PRO info;
    node *left, *right;
};
typedef struct node* Tree;

node* get_node(PRO x) {
    node *p = new node();
    p->info = x;
    p->left = p->right = nullptr;
    return p;
}

void insert(Tree &T, PRO x) {
    if(T) {
        if(T->info.id > x.id) insert(T->left, x);  
        if(T->info.id < x.id) insert(T->right, x);  
    } else {
        T = get_node(x);
    }
}

void inputTree(Tree &T) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        PRO x;
        cin >> x.id;
        cin.ignore(); getline(cin, x.name);
        getline(cin, x.type);
        cin >> x.year;
        cin >> x.warranty;
        insert(T, x);        
    }
}
//NLR
void listProduct(Tree T, string type) {
    if(T) {
        if(T->info.type == type) {
            cout << "\n" << T->info.id << "\t" << T->info.name << "\t";
            cout << T->info.type << "\t" << T->info.year << "\t" << T->info.warranty << "\n";
        }
        if(T->left) listProduct(T->left, type);
        if(T->right) listProduct(T->right, type);
    }
}
int dem = 0;
int countProduct(Tree &T, int year) {
    if(T) {
        if(T->info.warranty > year) dem++;
        if(T->left) countProduct(T->left, year);
        if(T->right) countProduct(T->right, year);
    }
    return dem;
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

