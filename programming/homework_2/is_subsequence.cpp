
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
    int x;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}
void add_tail(List &l, int x){
    Node*p = new Node;
    p->val = x;
    p->next = NULL;

    if (l.head == NULL){
        l.head = l.tail = p;
    } else {
        l.tail->next = p;   
        l.tail = p;
    }
}

void xuat(List &l){
    for(Node *p = l.head; p != NULL; p = p->next){
        cout << p->val << " ";
    }
    cout << endl;
}
bool is_subsequence(List &x, List &y) {
    Node *px = x.head;
    Node *py = y.head;

    int len_x = 0, len_y = 0;
    Node *temp = px;
    while (temp) { len_x++; temp = temp->next; }
    temp = py;
    while (temp) { len_y++; temp = temp->next; }

    if (len_x > len_y) {
        std::swap(px, py);
        std::swap(len_x, len_y);
    }

    while (py) {
        if (px->val == py->val) {
            px = px->next;
            if (!px) return true;
        }
        py = py->next;
    }

    return false;
}






int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    List lists[2];

    for(int i = 0; i < 2; i++){
        list_initializing(lists[i]);
        int x;
        do{
            cin >> x;
            if (x != -1) add_tail(lists[i], x);
            else break;
        } while(true);
    }

    if ( is_subsequence(lists[0], lists[1])) cout << "TRUE";
    else cout << "FALSE";


    return 0;
}
