#include <iostream>
#include <queue>
using namespace std;

// Define structure for a Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Insert a new node at the first empty position (Level-order)
void insert(Node*& root, int value) {
    Node* newNode = new Node(value);

    if (root == nullptr) {
        root = newNode;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == nullptr) {
            temp->left = newNode;
            return;
        } else {
            q.push(temp->left);
        }

        if (temp->right == nullptr) {
            temp->right = newNode;
            return;
        } else {
            q.push(temp->right);
        }
    }
}

// Search for a value in the tree using BFS
bool search(Node* root, int key) {
    if (root == nullptr) return false;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->data == key) return true;

        if (temp->left != nullptr) q.push(temp->left);
        if (temp->right != nullptr) q.push(temp->right);
    }

    return false;
}

// Breadth First Traversal (Level Order)
void breadthFirstTraversal(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    cout << "Breadth First Traversal (Level Order): ";
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
    cout << endl;
}

// Preorder Traversal (Root, Left, Right)
void preorderTraversal(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Postorder Traversal (Left, Right, Root)
void postorderTraversal(Node* root) {
    if (root == nullptr) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// Main function to test the operations
int main() {
    Node* root = nullptr;

    // Insert elements into the tree
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);

    // Traversals
    breadthFirstTraversal(root);

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    // Search
    int key = 30;
    cout << "Searching for " << key << ": ";
    cout << (search(root, key) ? "Found" : "Not Found") << endl;

    return 0;
}
