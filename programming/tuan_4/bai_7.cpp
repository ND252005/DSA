
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

void addTail(DList &l, int x) {
    DNode *p = get_node(x);
    if(l.pHead == nullptr){
        l.pHead = l.pTail = p;
        l.pHead->pPrev = l.pTail ->pNext = nullptr;
    } else {
        l.pTail->pNext = p;
        p ->pPrev = l.pTail;
        p->pNext = nullptr;
        l.pTail = p;
    }

}

void addHead(DList &l, int x) {
    DNode *p = get_node(x);
    if(l.pHead == nullptr){
        l.pHead = l.pTail = p;
        l.pHead->pPrev = l.pTail ->pNext = nullptr;
    } else {
        l.pHead ->pPrev = p;
        p->pNext = l.pHead;
        l.pHead = p;
        l.pHead->pPrev = nullptr; 
    }
}

void createList(DList &l) {
    int k; cin >> k;
    while(k != -1){
        addTail(l, k);
        cin >> k;
    }
}
void printList(DList l) {
    DNode *p = l.pHead;
    if(p == nullptr) cout << "List is empty";
    while(p != nullptr){
        cout << p->info << ' ';
        p = p->pNext;
    }
}

void addAfter(DList &l, int x, int y) {
    DNode *p1 = l.pHead;
    DNode *p2 = get_node(y);
    if(l.pHead == nullptr) {
        cout << "\nCan't find the value "<<x;
        return;
    }

    if(l.pTail->info == x) {
        l.pTail->pNext = p2;
        p2->pPrev = l.pTail;
        p2->pNext = nullptr;
        l.pTail = p2;
        return;
    }

    while(p1) {
        if(p1->info == x) {
            p2->pNext = p1->pNext;
            p1->pNext->pPrev = p2;
            p1->pNext = p2;
            p2->pPrev = p1;
            return;
        }
        p1 = p1->pNext;
    }
    cout << "\nCan't find the value "<<x;
}

void addBefore(DList &l, int x, int y) {
    DNode *p1 = l.pHead;
    DNode *p2 = get_node(y);
    if(l.pHead == nullptr) {
        cout << "\nCan't find the value "<<x;
        return;
    }
    if(l.pHead->info == x) {
        l.pHead ->pPrev = p2;
        p2->pNext = l.pHead;
        p2->pPrev = nullptr;
        l.pHead = p2;
        return;
    }
    while(p1){
        if(p1->info == x) {
            p1->pPrev->pNext = p2;
            p2->pPrev = p1->pPrev;
            p2->pNext = p1;
            p1->pPrev = p2;
            return; 
        }
        p1 = p1->pNext;
    }
    cout << "\nCan't find the value "<<x;
}
void addAfterMulti(DList &l, int x, int y) {
    DNode *p1 = l.pHead;
    DNode *p2;
    bool found = false;  // Cờ để kiểm tra xem có tìm thấy giá trị x không

    while (p1) {
        if (p1->info == x) {
            found = true;
            p2 = get_node(y);

            if (p1 == l.pTail) {
                // Nếu p1 là pTail, thêm p2 vào cuối danh sách
                l.pTail->pNext = p2;
                p2->pPrev = l.pTail;
                p2->pNext = nullptr;
                l.pTail = p2;
            } else {
                // Nếu không, chèn p2 sau p1
                p2->pNext = p1->pNext;
                p1->pNext->pPrev = p2;
                p1->pNext = p2;
                p2->pPrev = p1;
            }
        }
        p1 = p1->pNext;
    }

    if (!found) {
        cout << "\nCan't find the value " << x;
    }
}

void addBeforeMulti(DList &l, int x, int y) {
    DNode *p1 = l.pHead;
    DNode *p2;
    bool found = false;  // Cờ để kiểm tra xem có tìm thấy giá trị x không

    while (p1) {
        if (p1->info == x) {
            found = true;
            p2 = get_node(y);

            if (p1 == l.pHead) {
                // Nếu p1 là pHead, thêm p2 vào đầu danh sách
                l.pHead->pPrev = p2;
                p2->pNext = l.pHead;
                p2->pPrev = nullptr;
                l.pHead = p2;
            } else {
                // Nếu không, chèn p2 trước p1
                p1->pPrev->pNext = p2;
                p2->pPrev = p1->pPrev;
                p2->pNext = p1;
                p1->pPrev = p2;
            }
        }
        p1 = p1->pNext;
    }

    if (!found) {
        cout << "\nCan't find the value " << x;
    }
}
void removeHead(DList &l) {
    if (l.pHead == nullptr) {
        cout << "\nList is empty. Can't delete";
        return;
    }

    char choice;
    cout << "\nDo you want to delete the first element?(y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        if (l.pHead == l.pTail) {
            // Nếu danh sách chỉ có 1 phần tử
            delete l.pHead;
            l.pHead = l.pTail = nullptr;
            cout << "\nThe list becomes empty";
        } else {
            // Xóa phần tử đầu tiên
            DNode *temp = l.pHead;
            l.pHead = l.pHead->pNext;
            l.pHead->pPrev = nullptr;
            delete temp;
        }
    }
}

void removeTail(DList &l) {
    if (l.pTail == nullptr) {
        cout << "\nList is empty. Can't delete";
        return;
    }

    char choice;
    cout << "\nDo you want to delete the last element?(y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        if (l.pHead == l.pTail) {
            // Nếu danh sách chỉ có 1 phần tử
            delete l.pTail;
            l.pHead = l.pTail = nullptr;
            cout << "\nThe list becomes empty";
        } else {
            // Xóa phần tử cuối
            DNode *temp = l.pTail;
            l.pTail = l.pTail->pPrev;
            l.pTail->pNext = nullptr;
            delete temp;
        }
    }
}
void removeNode(DList &l, int x) {
    if (l.pHead == nullptr) {
        cout << "\nList is empty. Can't delete";
        return;
    }

    DNode *p = l.pHead;
    while (p != nullptr && p->info != x) {
        p = p->pNext;
    }

    if (p == nullptr) {
        cout << "\nCan't find the value " << x;
        return;
    }

    char choice;
    cout << "\nDo you want to delete " << x << " ?(y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        if (p == l.pHead) {
            removeHead(l);
        } else if (p == l.pTail) {
            removeTail(l);
        } else {
            p->pPrev->pNext = p->pNext;
            p->pNext->pPrev = p->pPrev;
            delete p;
        }
        if (l.pHead == nullptr) cout << "\nThe list becomes empty";
    }
}

void removeMultiNodes(DList &l, int x) {
    if (l.pHead == nullptr) {
        cout << "\nList is empty. Can't delete";
        return;
    }

    DNode *p = l.pHead;
    bool found = false;

    cout << "\nDo you want to delete " << x << "s ?(y/n): ";
    char choice;
    cin >> choice;

    if (choice != 'y' && choice != 'Y') return;

    while (p != nullptr) {
        if (p->info == x) {
            found = true;
            DNode *temp = p;
            p = p->pNext;

            if (temp == l.pHead) {
                removeHead(l);
            } else if (temp == l.pTail) {
                removeTail(l);
            } else {
                temp->pPrev->pNext = temp->pNext;
                temp->pNext->pPrev = temp->pPrev;
                delete temp;
            }
        } else {
            p = p->pNext;
        }
    }

    if (!found) {
        cout << "\nCan't find the value " << x;
    } else if (l.pHead == nullptr) {
        cout << "\nThe list becomes empty";
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
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 5:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfter(L,x,y);
            break;
        case 6:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBefore(L,x,y);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
