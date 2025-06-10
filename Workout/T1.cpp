#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    int data;
    cout << "Enter Data: " << endl;
    cin >> data;
    root = new Node(data);
    if(data==-1){
        return 0;
    }

    cout << "Enter Data for Inserting in left of " << data << endl;
    root->left= buildTree(root->left);
    cout << "Enter Data for Inserting in Right of " << data << endl;
    root->right= buildTree(root->right);
    return root;
}

// 1. Implement a Binary Tree in C++ in which the following
// functionalities will exist:
// ●Insertion();
// ●Display();
// ●Size();
// ●ShiftUp();

void ShiftUp(Node* root){
    if(root==NULL){
        return;
    }
    ShiftUp(root->left);
    cout << root->data << " ";
    ShiftUp(root->right);
}

void Display(Node* root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    Display(root->left);
    Display(root->right);
    // cout << endl;
}

int Size(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1 + Size(root->left) + Size(root->right);
}



bool isCompleteBinaryTree(Node* root, int index, int numberNodes){
    if(root==NULL){
        return true;
    }
    if(index>=numberNodes){
        return false;
    }
    return isCompleteBinaryTree(root->left, 2*index+1, numberNodes) && isCompleteBinaryTree(root->right, 2*index+2, numberNodes);
}
int main()
{
    Node* root = NULL;
    root = buildTree(root);
    cout << "Tree Created Successfully!" << endl;

    cout << "Display Tree: ";
    Display(root);
    cout << endl;
    cout << "Size of Tree: " << Size(root) << endl;
    cout << "Shift Up Tree: ";
    ShiftUp(root);
    cout << endl;

    int index = 0;
    int numberNodes = Size(root);
    if(isCompleteBinaryTree(root, index, numberNodes)){
        cout << "The tree is a complete binary tree." << endl;
    } else {
        cout << "The tree is not a complete binary tree." << endl;
    }

    

    return 0;
}