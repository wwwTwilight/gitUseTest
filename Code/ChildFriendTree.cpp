#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* firstChild;
    TreeNode* nextSibling;
    
    TreeNode(int x) : val(x), firstChild(nullptr), nextSibling(nullptr) {}
};

void preOrder(TreeNode* root)
{
    if (root == nullptr)
        return;

    cout << root->val << " ";
    preOrder(root->firstChild);
    preOrder(root->nextSibling);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    
    root->firstChild = new TreeNode(2);
    root->firstChild->nextSibling = new TreeNode(3);
    root->firstChild->firstChild = new TreeNode(4);
    root->firstChild->firstChild->nextSibling = new TreeNode(5);

    preOrder(root);
}