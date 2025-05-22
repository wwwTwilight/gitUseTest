#include<iostream>
#include<vector>
#include<algorithm> 
#include<map>
#include<unordered_map>
#include<stdlib.h>
#include<time.h>
using namespace std;
template <class T>
struct ListNode {
    T val;
    ListNode *next;
    ListNode *pre;
    ListNode() : val(0), next(NULL), pre(NULL) {}
    ListNode(T x) : val(x), next(NULL), pre(NULL) {}
    ListNode(T x, ListNode<T> *next) : val(x), next(next), pre(NULL) {}
    ListNode(T x, ListNode<T> *next, ListNode<T> *pre) : val(x), next(next), pre(pre) {}
};
template <class T>
class LinkList
{
private:
    ListNode<T>* head;
    ListNode<T>* tail;
public:
    LinkList()
    {
        head = new ListNode<T>;
        tail = head;
    }
    void push(T val)
    {
        ListNode<T>* node = new ListNode<T>(val);
        node->pre = tail;
        tail->next = node;
        tail = node;
    }

    void pop()
    {
        if (tail == head)
        {
            return;
        }
        ListNode<T>* node = tail;
        tail = tail->pre;
        tail->next = NULL;
        delete node;
    }

    T top()
    {
        return tail->val;
    }
};

int main()
{
    LinkList<int> LinkListToStack;
    LinkListToStack.push(1);
    LinkListToStack.push(2);
    LinkListToStack.push(3);
    cout << LinkListToStack.top() << endl;
    LinkListToStack.pop();
    cout << LinkListToStack.top() << endl;
    LinkListToStack.pop();
    cout << LinkListToStack.top() << endl;
}
