#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root) {
    cout << "Enter Data: " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1) {
        return NULL;
    }

    cout << "Enter Data for Inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter Data for Inserting in Right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void reverseLevelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    stack<Node*> s;

    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Push the current node into the stack
        s.push(temp);

        // Push right child first, then left child (to reverse the order)
        if (temp->right) {
            q.push(temp->right);
        }
        if (temp->left) {
            q.push(temp->left);
        }
    }

    // Print nodes in reverse order from the stack
    while (!s.empty()) {
        cout << s.top()->data << " ";
        s.pop();
    }
}

int main() {
    Node* root = NULL;

    root = buildTree(root);
    // Example input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // Reverse level order
    cout << "Printing the Reverse Level Order Traversal Output: ";
    reverseLevelOrderTraversal(root);

    return 0;
}