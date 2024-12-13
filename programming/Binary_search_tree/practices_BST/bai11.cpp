#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* left, *right;
};

struct Node_queue {
    Node* info;
    Node_queue *next;
};
typedef struct Node* Tree;


class queue {
private: 
    Node_queue* head;
    Node_queue* tail;
public:
    queue() {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void push(Node* value) {
        Node_queue* newNode = new Node_queue();
        newNode->info = value;
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() {
        Node_queue* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
    Node* peek() {
        return head->info;
    }

    ~queue() {
        while (!isEmpty()) {
            pop();
        }
    }
};
class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->info = value;
        newNode->right = top;
        top = newNode;
    }

    void pop() {
        Node* temp = top;
        top = top->right;
        cout << temp->info << " ";
        delete temp;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

//tao tree
Node* get_node(int x) {
    Node* p = new Node();
    p->info = x;
    p->left = p->right = nullptr;
    return p;
}
void insert_node(Tree &T, int x) {
    if(T) {
        if(T->info == x) return;
        if(T->info > x) insert_node(T->left, x);
        if(T->info < x) insert_node(T->right, x);
    } else {
        T = get_node(x);
    }
}
void input_tree(Tree &T) {
    int x; cin >> x;
    while(x != -1) {
        insert_node(T, x);
        cin >> x;
    }
}

void NLR(Tree T, Stack &S) {
    if(T) S.push(T->info);
    if(T->left) NLR(T->left, S);
    if(T->right) NLR(T->right, S);
}
void output_tree(Tree T, Stack &S, queue &Q) {
    if(!T) return;
    Q.push(T);
    while(!Q.isEmpty()) {
        Tree current = Q.peek();
        Q.pop();
        S.push(current->info);
        if(current->left) {
            Q.push(current->left);
        }
        if(current->right) {
            Q.push(current->right);
        }
    }
}

int main() {
    Tree T = nullptr;
    input_tree(T);
    Stack S;
    queue Q;
    output_tree(T, S, Q);
    while(!S.isEmpty()) S.pop();
}