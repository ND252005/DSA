
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct node {
    int info;
    node *next;
};
struct List {
    node *head, *tail;
};
void Init(List &L){
  
    L.head = L.tail = nullptr;
}




int main()
{
    List L;
    Init(L);
    // int n; cout<<"Enter a number: "; cin>>n;
    // cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    // inputList(L,n);
    // cout<<"\nThe created Linked List: ";
    // outputList(L);


    // cout<<"\nThe maximum value: ";
    // node *p = findMax(L);
    // if(p) cout<<p->info;

    return 0;
}
