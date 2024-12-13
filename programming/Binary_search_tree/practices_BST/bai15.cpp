
#include <bits/stdc++.h>
using namespace std;


class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:

    void preOrder(Node *root) {
        if (root == NULL)
            return;

stack<Node*> s;
s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();

        cout << current->data << " ";

        if (current->right != NULL)
            s.push(current->right);
        if (current->left != NULL)
            s.push(current->left);
    }

    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        } else {
            Node* current;
            if (data <= root->data) {
                current = insert(root->left, data);
                root->left = current;
            } else {
                current = insert(root->right, data);
                root->right = current;
            }
            return root;
        }
    }
}



    /* SV phai viet ca ham insert
    Node* insert(Node* root, int data);
     */

}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.preOrder(root);

    return 0;
}
