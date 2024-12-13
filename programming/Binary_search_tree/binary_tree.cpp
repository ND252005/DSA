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

//Kiểm tra có phần tử không, trả về giá trị kiểu node
node* Search(Tree &T, int x) {
    if (!T || T->info == x) return T;
    node* p = Search(T->left, x);
    if (p) return p;
    return Search(T->right, x);
}
// thêm node vào bên trái của giá trị cho trước 
void SetLeft(node *p, int c) {
    if (p == nullptr) {
        cout << "Node khong ton tai\n";
        return;
    }
    if (p->left == nullptr) {
        p->left = getNode(c);
    } else {
        cout << "Da co node con ben trai\n";
    }
}
//thêm node vào bên phải của giá trị cho trước 
void SetRight(node *p, int c) {
    if (p == nullptr) {
        cout << "Node khong ton tai\n";
        return;
    }
    if (p->right == nullptr) {
        p->right = getNode(c);
    } else {
        cout << "Da co node con ben phai\n";
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



int main()
{
	Tree T = NULL;
	int x,b,c; char a;
	cin>>x;	T=getNode(x); // tao nut goc
	while(true)
    {
        cin>>a; // Ky tu cho biet chen vao trai hay phai
        if(a!='L'&& a!='R') break; // Neu khong phai L hoac R thi ket thuc viec tao cay
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c); // chen c vao ben trai b
        else if (a=='R') SetRight(Search(T,b),c); // chen c vao ben phai b
    }
	cout<<"\nLNR: "; LNR(T); cout<<endl;

	return 0;
}
