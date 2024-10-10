
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

struct List {
    Node* head;
    List() : head(NULL) {}
};

void init(List& L) {
    L.head = NULL;
}

void chenCuoi(List& L, int x) {
    Node* newNode = new Node(x);
    if (!L.head) {
        L.head = newNode;
    } else {
        Node* temp = L.head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void inputList(List& L, int n) {
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        chenCuoi(L, num);
    }
}

void MySort(List& L) {
    Node* i = L.head;
    while (i && i->next) {
        Node* min = i;
        Node* j = i->next;
        while (j) {
            if (j->data < min->data) {
                min = j;
            }
            j = j->next;
        }
        if (min != i) {
            swap(i->data, min->data);
        }
        i = i->next;
    }
}

int MySearch(List& L, int x) {
    Node* temp = L.head;
    int pos = 0;
    while (temp) {
        if (temp->data == x) {
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1; // Không tìm thấy
}

void outputList(List& L) {
    Node* temp = L.head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int n; cin>>n;
    List L;init (L);
    inputList(L,n);
    MySort(L);
    cout<<"Sorted List: ";
    outputList(L);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x; cin>>x;
    cout<<x<<endl;
    int result = MySearch(L,x);
    if (result ==-1) cout<<x<<" is not found";
    else cout<<x<<" is found at the position " << result;

	return 0;
}

