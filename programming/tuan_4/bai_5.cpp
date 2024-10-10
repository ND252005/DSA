
#include  <iostream>
using namespace std;

struct DNode
{
	int info;
	DNode *pNext, *pPrev;
};

struct DList
{
	DNode *pHead, *pTail;
};

void init(DList &L){
    L.pHead = L.pTail = nullptr;
}

DNode* get_node(int x) {
    DNode *p = new DNode;
    p->info = x;
    p->pNext = p->pPrev = nullptr;
    return p;
}

void add_tail(DList &l, int x) {
    DNode *p = get_node(x);
    l.pTail->pNext = p;
    p ->pPrev = l.pTail;
    p->pNext = nullptr;
    l.pTail = p;
}

void createList(DList &l) {
    int k; cin >> k;
    while(k != -1){
        if(l.pHead == nullptr){
            DNode *p = get_node(k);
            l.pHead = l.pTail = p;
        }else{
            add_tail(l, k);
        }
        cin >> k;
    }
}
void printList(DList l){
    DNode *p = l.pHead;
    if(p == nullptr) cout << "List is empty";
    while(p != nullptr){
        cout << p->info << ' ';
        p = p->pNext;
    }
}



int main()
{
	DList L;
	init(L);
	int x,y,choice;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n20. Exit"<<endl;

	while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
