#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;

// 二叉树节点的定义
struct Node {
    int data;
    int height;
    Node *left;
    Node *right;
    Node() : data(0),height(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), height(0), left(nullptr), right(nullptr) {}
    Node(int x, int y) : data(x), height(y), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

void rightRotation(Node* &node);
void leftRotation(Node* &node);
void DoubleRotationLR(Node* &node);
void DoubleRotationRL(Node* &node);

// 前序遍历
void preOrderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->data << " "; // 访问根节点
    preOrderTraversal(node->left); // 遍历左子树
    preOrderTraversal(node->right); // 遍历右子树
}

// 中序遍历
void inOrderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    inOrderTraversal(node->left); // 遍历左子树
    cout << node->data << " "; // 访问根节点
    inOrderTraversal(node->right); // 遍历右子树
}

// 后序遍历
void postOrderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    postOrderTraversal(node->left); // 遍历左子树
    postOrderTraversal(node->right); // 遍历右子树
    cout << node->data << " "; // 访问根节点
}

//重制整个树的高度信息
int heightReset(Node* node)
{
    if (node == nullptr) {
        return 0;
    }
    node->height = 1 + max(heightReset(node->left), heightReset(node->right));
    return node->height;
}



// 广度优先遍历
void breadthFirstOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
}

void insert(Node* &root, int data) 
{
    if(root == NULL)
    {
        root = new Node(data);
    }
    else 
    {
        if(root->data > data)
        {
            insert(root->left, data);
            if(abs(root->left->height - root->right->height) == 2)
            {
                if(root->left->data > data)
                {
                    rightRotation(root);
                }
                else
                {
                    DoubleRotationLR(root);
                }
            }
        }
        else if(root->data <= data)
        {
            insert(root->right, data);
            if(abs(root->left->height - root->right->height) == 2)
            {
                if(root->right->data < data)
                {
                    leftRotation(root);
                }
                else
                {
                    DoubleRotationRL(root);
                }
            }
        }
    }

}

void rightRotation(Node* &node)
{
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node = temp;
}

void leftRotation(Node* &node)
{
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node = temp;
}

void DoubleRotationLR(Node* &node)
{
    leftRotation(node->right);
    rightRotation(node);
}

void DoubleRotationRL(Node* &node)
{
    rightRotation(node->right);
    leftRotation(node);
}



int main() 
{
    Node* root = new Node(25);
    root->left = new Node(21);
    root->right = new Node(30);
    root->left->left = new Node(19);
    root->left->right = new Node(22);
    // root->left->left->right = new Node(20);
    // root->right->left = new Node(6);
    // root->right->right = new Node(9);
    heightReset(root);

    // cout << "前序遍历: ";
    // preOrderTraversal(root);
    // cout << endl;

    // cout << "中序遍历: ";
    // inOrderTraversal(root);
    // cout << endl;

    // cout << "后序遍历: ";
    // postOrderTraversal(root);
    // cout << endl;

    cout << "广度优先遍历: ";
    breadthFirstOrder(root);
    cout << endl;
    
    insert(root, 18);
    //rightRotation(root);

    // cout << root->left->data << endl;
    cout << "广度优先遍历: ";
    breadthFirstOrder(root);
    cout << endl;
}
