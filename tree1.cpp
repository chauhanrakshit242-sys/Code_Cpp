#include<iostream>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Build Tree (Preorder)
Node* buildtree(Node* root)
{
    cout << "Enter the data: ";
    int x;
    cin >> x;

    if(x == -1)
    {
        return NULL;
    }

    root = new Node(x);

    cout << "Enter the left child of " << x << endl;
    root->left = buildtree(root->left);

    cout << "Enter the right child of " << x << endl;
    root->right = buildtree(root->right);

    return root;
}

// Level Order Traversal (BFS)
void levelorder(Node* root)
{
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left)
        {
            q.push(temp->left);
        }

        if(temp->right)
        {
            q.push(temp->right);
        }
    }
}
void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root>right);
}
void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    Node* root = NULL;

    // Build tree
    root = buildtree(root);

    // Print level order traversal
    cout << "\nLevel Order Traversal: ";
    levelorder(root);

    return 0;
}