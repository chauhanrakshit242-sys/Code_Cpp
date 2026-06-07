#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert into BST
Node* insert(Node* root, int val) {
    if(root == NULL) {
        return new Node(val);
    }

    if(val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Take input from user
void takeInput(Node* &root) {
    int data;
    cout << "Enter values (-1 to stop): ";

    cin >> data;

    while(data != -1) {
        root = insert(root, data);
        cin >> data;
    }
}

// Inorder Traversal
void inorder(Node* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
bool ispersent(Node* root , int x)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==x)
    {
        return true;
    }
    if(root->data>x)
    {
        return ispersent(root->left,x);
    }
    else
    {
       return ispersent(root->right,x);
    }
    return false;
}
pair<int,int> min_max(Node* root)
{
    if(root == NULL)
    {
        return {0, 0};  // edge case
    }

    Node* temp = root;

    // Find Minimum
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    int minVal = temp->data;

    temp = root;

    // Find Maximum
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    int maxVal = temp->data;

    return {minVal, maxVal};
}
// Main
int main() {
    int x;
    cout<<"Enetr the data for Search";
    cin>>x;
    Node* root = NULL;

    takeInput(root);
    cout << "Inorder Traversal: ";
    inorder(root);
    bool ans=ispersent(root,x);
    cout<<endl;
    cout<<"Is persent"<<ans;
    return 0;
}