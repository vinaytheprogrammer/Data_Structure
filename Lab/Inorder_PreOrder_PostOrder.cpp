#include <bits/stdc++.h>
using namespace std;


//Binary Tree Traversing (Accessing Nodes) Using Inorder, PostOrder , PreOrder
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int dt)
    {
        data = dt;
        left = NULL;
        right = NULL;
    }
};
class BinaryTress
{
    Node *root;

public:
    BinaryTress()
    {
        root = NULL;
    }
    void insert(int data)
    {
        Node *newNode = new Node(data);
        if (root == NULL)
        {
            root = newNode;
            return;
        }
        Node *current = root;
        while (1)
        {
            if (data < current->data)
            {
                if (current->left == NULL)
                {
                    current->left = newNode;
                    return;
                }
                current = current->left;
            }
            else
            {
                if (current->right == NULL)
                {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            }
        }
    }
    void inorderTraversal(Node *current)
    {
        if (current == NULL)
        {
            return;
        }
        inorderTraversal(current->left);
        cout << current->data << " ";
        inorderTraversal(current->right);
    }
    void preorderTraversal(Node *current)
    {
        if (current == NULL)
        {
            return;
        }
        cout << current->data << " ";
        preorderTraversal(current->left);
        preorderTraversal(current->right);
    }


    void postorderTraversal(Node *current)
    {
        if (current == NULL)
        {
            return;
        }
        postorderTraversal(current->left);
        postorderTraversal(current->right);
        cout << current->data << " ";
    }
    void inorder()
    {
        inorderTraversal(root);
        cout << endl;
    }
    void preorder()
    {
        preorderTraversal(root);
        cout << endl;
    }
    void postorder()
    {
        postorderTraversal(root);
        cout << endl;
    }
};
int main()
{
    BinaryTress b1;
    b1.insert(3);   // first is Root 
 

    b1.insert(2); // root's left 
    b1.insert(-1); // root's left left
    b1.insert(4);  // root's right
    b1.insert(5);  // root's right right 
    b1.insert(6);  // root's right right right

    cout << "Inorder\n";
    b1.inorder();
    cout << "Preorder\n";
    b1.preorder();
    cout << "Postorder\n";
    b1.postorder();
}