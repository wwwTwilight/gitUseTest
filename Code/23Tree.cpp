#include <iostream>
using namespace std;

class Node {
public:
    int val[2];     // 存放节点中的值，最多两个
    Node* child[3]; // 存放子节点，最多三个
    bool isTwoNode; // 标记是否为2节点

    Node(int value) {
        val[0] = value;
        val[1] = -1; // -1表示没有第二个值
        for (int i = 0; i < 3; i++) {
            child[i] = nullptr;
        }
        isTwoNode = true; // 初始为2节点
    }

    bool isLeaf() {
        return (child[0] == nullptr && child[1] == nullptr && child[2] == nullptr);
    }
};

class TwoThreeTree {
private:
    Node* root;

    // 插入节点
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (node->isLeaf()) {
            return splitAndInsert(node, value);
        }

        if (value < node->val[0]) {
            node->child[0] = insert(node->child[0], value);
        } else if (node->isTwoNode || value < node->val[1]) {
            node->child[1] = insert(node->child[1], value);
        } else {
            node->child[2] = insert(node->child[2], value);
        }

        return node;
    }

    // 节点分裂与插入
    Node* splitAndInsert(Node* node, int value) {
        if (node->isTwoNode) {
            if (value < node->val[0]) {
                node->val[1] = node->val[0];
                node->val[0] = value;
            } else {
                node->val[1] = value;
            }
            node->isTwoNode = false;
            return node;
        } else {
            int middleValue;
            Node* newLeft;
            Node* newRight;

            if (value < node->val[0]) {
                middleValue = node->val[0];
                newLeft = new Node(value);
                newRight = new Node(node->val[1]);
            } else if (value < node->val[1]) {
                middleValue = value;
                newLeft = new Node(node->val[0]);
                newRight = new Node(node->val[1]);
            } else {
                middleValue = node->val[1];
                newLeft = new Node(node->val[0]);
                newRight = new Node(value);
            }

            if (node == root) {
                root = new Node(middleValue);
                root->child[0] = newLeft;
                root->child[1] = newRight;
                return root;
            } else {
                Node* parent = new Node(middleValue);
                parent->child[0] = newLeft;
                parent->child[1] = newRight;
                return parent;
            }
        }
    }

public:
    TwoThreeTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void print(Node* node, int level = 0) {
        if (node == nullptr) return;
        print(node->child[2], level + 1);
        if (!node->isTwoNode) {
            for (int i = 0; i < level; i++) cout << "    ";
            cout << node->val[1] << endl;
        }
        print(node->child[1], level + 1);
        for (int i = 0; i < level; i++) cout << "    ";
        cout << node->val[0] << endl;
        print(node->child[0], level + 1);
    }

    void display() {
        print(root);
    }
};

int main() {
    TwoThreeTree tree;
    int values[] = {10, 20, 5, 6, 12, 30, 7, 17};
    
    for (int value : values) {
        tree.insert(value);
    }

    tree.display();
    
    return 0;
}
