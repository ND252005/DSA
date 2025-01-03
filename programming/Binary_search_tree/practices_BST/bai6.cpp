struct Node {
    int data;
    Node* left;
    Node* right;
};
typedef Node* Tree;

Node* getNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* Search(Node* rootNode, int targetValue) {
    if (rootNode == nullptr || rootNode->data == targetValue)
        return rootNode;
    Node* leftResult = Search(rootNode->left, targetValue);
    return leftResult ? leftResult : Search(rootNode->right, targetValue);
}

void SetLeft(Node* parentNode, int value) {
    if (parentNode == nullptr || parentNode->left != nullptr) return; 
    parentNode->left = getNode(value);
}

void SetRight(Node* parentNode, int value) {
    if (parentNode == nullptr || parentNode->right != nullptr) return; 
    parentNode->right = getNode(value);
}

void LNR(Node* rootNode) {
    if (rootNode == nullptr) return;
    LNR(rootNode->left);
    cout << rootNode->data << " ";
    LNR(rootNode->right);
}

void DeleteLeft(Node* parentNode) {
    if (parentNode == nullptr) {
        cout << "Node khong ton tai\n";
        return;
    }
    if (parentNode->left == nullptr) {
        cout << "Khong co node ben trai\n";
        return;
    }
    if (parentNode->left->left != nullptr || parentNode->left->right != nullptr) {
        cout << "Khong la node la nen khong xoa duoc\n";
        return;
    }
    delete parentNode->left; 
    parentNode->left = nullptr; 
}

void DeleteRight(Node* parentNode) {
    if (parentNode == nullptr) {
        cout << "Node khong ton tai\n";
        return;
    }
    if (parentNode->right == nullptr) {
        cout << "Khong co node ben phai\n";
        return;
    }
    if (parentNode->right->left != nullptr || parentNode->right->right != nullptr) {
        cout << "Khong la node la nen khong xoa duoc\n";
        return;
    }
    delete parentNode->right; 
    parentNode->right = nullptr; 
}