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
        head = NULL;
        tail = NULL;
    }
    void push(T val)
    {
        if(head == NULL)
        {
            head = new ListNode<T>(val);
            tail = head;
        }
        else
        {
            ListNode<T>* node = new ListNode<T>(val);
            node->pre = tail;
            tail->next = node;
            tail = node;
        } 
    }

    void pop()
    {
        if (head == NULL) 
        {
            // 队列为空
            cout << "Queue is empty, cannot pop." << endl;
            return;
        }
        if (head == tail) 
        {
            // 只有一个元素的情况
            delete head;
            head = NULL;
            tail = NULL;
        } else 
        {
            // 多个元素的情况
            ListNode<T>* node = head;
            head = head->next;
            head->pre = NULL;
            delete node;
        }
    }

    T front()
    {
        if (head == NULL)
        {
            return -1;
        }
        return head->val;
    }
};

int main()
{
    LinkList<int> LinkListToQueue;
    LinkListToQueue.push(1);
    cout << LinkListToQueue.front() << endl;
    LinkListToQueue.push(2);
    cout << LinkListToQueue.front() << endl;
    LinkListToQueue.push(3);
    cout << LinkListToQueue.front() << endl;
    LinkListToQueue.pop();
    cout << LinkListToQueue.front() << endl;
    LinkListToQueue.pop();
    cout << LinkListToQueue.front() << endl;
    LinkListToQueue.pop();
    cout << LinkListToQueue.front() << endl;
}
