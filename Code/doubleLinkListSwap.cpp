#include<iostream>
#include<vector>
#include<algorithm> 
#include<map>
#include<unordered_map>
#include<stdlib.h>
#include<time.h>
using namespace std;
//题目要求双向链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode *pre;
    ListNode() : val(0), next(NULL), pre(NULL) {}
    ListNode(int x) : val(x), next(NULL), pre(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next), pre(NULL) {}
    ListNode(int x, ListNode *next, ListNode *pre) : val(x), next(next), pre(pre) {}
};

class LinkList
{
private:
    ListNode* head;
public:
    //创建链表
    LinkList()
    {
        head = new ListNode;
    }

    ListNode* getHead()
    {
        return head;
    }

    void dataInput(vector<int> nums)
    {
        ListNode* cur = head;
        for(int i = 0; i < nums.size(); i++)
        {
            cur->val = nums[i];
            if(i != nums.size() - 1)
            {
                cur->next = new ListNode();
                cur->next->pre = cur;
                cur = cur->next;
            }
        }
    }

    //打印链表
    void printList()
    {
        ListNode* cur = head;
        while(cur != NULL)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void swapBehindNodes(ListNode* op)
    {
        //交换两个节点
        if(op->next == NULL)
        {
            cout << "Can't swap the last node with the next node" <<endl;
            return;
        }
        ListNode* cur = head;
        while(cur != op)
        {
            cur = cur->next;
            if(cur == op)
            {
                //交换节点顺序，不改变其数值
                cur->pre->next = cur->next;
                cur->next->pre = cur->pre;
                cur->next = cur->next->next;
                cur->next->pre = cur;
                cur->pre = cur->pre->next;
                cur->pre->next = cur;
            }
        }
    }
    void deleteNode(int val)
    {
        ListNode dummy(0, head);
        ListNode* ptr1 = &dummy;
        ListNode* ptr2 = head;
        if(ptr2 == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }
        while(ptr2 != NULL)
        {
            if(ptr2->val == val)
            {
                ptr2 = ptr2->next;
                delete ptr1->next;
                ptr1->next = ptr2;
            }
            else
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }
        this->head = dummy.next;
        return;
    }
};

int main()
{
    LinkList linkList;
    vector<int> nums = {1, 2, 3, 4, 5};
    linkList.dataInput(nums);//此链表根据输入的数组创建
    linkList.printList();
    linkList.swapBehindNodes(linkList.getHead()->next);//交换函数，传入的需要交换的节点的指针，将那个节点与其后一个节点交换
    linkList.printList();
    linkList.deleteNode(1);//删除val值为1的节点
    linkList.printList();
}