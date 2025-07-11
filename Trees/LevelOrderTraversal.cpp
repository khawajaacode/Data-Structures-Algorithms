#include <iostream>
#include<queue>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    
    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node* root) {

    cout << "Enter Data: " <<endl;
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }
    
    cout << "Enter Data for Inserting in left of " << data <<endl;
    root->left = buildTree(root->left);
    cout << "Enter Data for Inserting in Right of " << data <<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        
        q.pop();
        //purana Level complete ho chuka hai
        if (temp ==NULL)
        {
           cout << endl;
           if (!q.empty())
           {
            q.push(NULL);
           }
           
        }
        else{
            cout<< temp ->data<< " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }

        }

    }
    

}

int main()
{

    Node* root = NULL;

    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // level order
    cout << "Printing the Level Order Traversal Output ";
    levelOrderTraversal(root);

    

    return 0;
}