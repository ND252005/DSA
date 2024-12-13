#include <iostream>
using namespace std;

struct DNode {
    int info;
    DNode* pPrev;
    DNode* pNext;
};

struct DList {
    DNode* pHead;
    DNode* pTail;
};

void init(DList& L) {
    L.pHead = L.pTail = nullptr;
}

DNode* createDNode(int info) {
    DNode* newDNode = new DNode;
    newDNode->info = info;
    newDNode->pPrev = newDNode->pNext = nullptr;
    return newDNode;
}

void addHead(DList& L, int x) {
    DNode* newDNode = createDNode(x);
    if (L.pHead == nullptr) {
        L.pHead = L.pTail = newDNode;
    } else {
        newDNode->pNext = L.pHead;
        L.pHead->pPrev = newDNode;
        L.pHead = newDNode;
    }
}

void addTail(DList& L, int x) {
    DNode* newDNode = createDNode(x);
    if (L.pTail == nullptr) {
        L.pHead = L.pTail = newDNode;
    } else {
        newDNode->pPrev = L.pTail;
        L.pTail->pNext = newDNode;
        L.pTail = newDNode;
    }
}

void printList(const DList& L) {
    DNode* temp = L.pHead;
    while (temp != nullptr) {
        cout << temp->info << " ";
        temp = temp->pNext;
    }
    cout << endl;
}

void createList(DList& L) {
    int x;
    while (true) {
        cin >> x;
        if (x == -1) break;
        addTail(L, x);
    }
}

void addAfter(DList& L, int x, int y) {
    DNode* temp = L.pHead;
    while (temp != nullptr) {
        if (temp->info == x) {
            DNode* newDNode = createDNode(y);
            newDNode->pNext = temp->pNext;
            newDNode->pPrev = temp;
            if (temp->pNext != nullptr) {
                temp->pNext->pPrev = newDNode;
            } else {
                L.pTail = newDNode;
            }
            temp->pNext = newDNode;
            return;
        }
        temp = temp->pNext;
    }
    cout << "\nCan't find the value " << x;
}

void addBefore(DList& L, int x, int y) {
    DNode* temp = L.pHead;
    while (temp != nullptr) {
        if (temp->info == x) {
            DNode* newDNode = createDNode(y);
            newDNode->pNext = temp;
            newDNode->pPrev = temp->pPrev;
            if (temp->pPrev != nullptr) {
                temp->pPrev->pNext = newDNode;
            } else {
                L.pHead = newDNode;
            }
            temp->pPrev = newDNode;
            return;
        }
        temp = temp->pNext;
    }
    cout << "\nCan't find the value " << x;
}

void addAfterMulti(DList& L, int x, int y) {
    DNode* temp = L.pHead;
    bool found = false;
    while (temp != nullptr) {
        if (temp->info == x) {
            DNode* newDNode = createDNode(y);
            newDNode->pNext = temp->pNext;
            newDNode->pPrev = temp;
            if (temp->pNext != nullptr) {
                temp->pNext->pPrev = newDNode;
            } else {
                L.pTail = newDNode;
            }
            temp->pNext = newDNode;
            temp = newDNode->pNext;  // Move to the pNext element after the inserted one
            found = true;
        } else {
            temp = temp->pNext;
        }
    }
    if (!found) {
        cout << "\nCan't find the value " << x;
    }
}


void addBeforeMulti(DList& L, int x, int y) {
    DNode* temp = L.pHead;
    bool found = false;
    while (temp != nullptr) {
        if (temp->info == x) {
            DNode* newDNode = createDNode(y);
            newDNode->pNext = temp;
            newDNode->pPrev = temp->pPrev;
            if (temp->pPrev != nullptr) {
                temp->pPrev->pNext = newDNode;
            } else {
                L.pHead = newDNode;
            }
            temp->pPrev = newDNode;
            temp = newDNode->pNext;  // Move to the pNext element after the inserted one
            found = true;
        } else {
            temp = temp->pNext;
        }
    }
    if (!found) {
        cout << "\nCan't find the value " << x;
    }
}

int main() {
    DList L;
    init(L);
    int x, y, choice;

    cout << "MENU:";
    cout << "\n1. Create a DList";
    cout << "\n2. Print the DList";
    cout << "\n3. Insert a value at the front";
    cout << "\n4. Insert a value at the end";
    cout << "\n5. Insert a value after a given value (only for the first value found)";
    cout << "\n6. Insert a value before a given value (only for the first value found)";
    cout << "\n7. Insert a value after a given value (for all the same values)";
    cout << "\n8. Insert a value before a given value (for all the same values)";
    cout << "\n20. Exit" << endl;

    while (true) {
        cout << "\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout << "\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout << "\nEnter a number: ";
            cin >> x;
            addHead(L, x);
            break;
        case 4:
            cout << "\nEnter a number: ";
            cin >> x;
            addTail(L, x);
            break;
        case 5:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addAfter(L, x, y);
            break;
        case 6:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addBefore(L, x, y);
            break;
        case 7:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addAfterMulti(L, x, y);
            break;
        case 8:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addBeforeMulti(L, x, y);
            break;
        case 20:
            cout << "\nGOOD BYE";
            return 0;
        }
    }

    return 0;
}
