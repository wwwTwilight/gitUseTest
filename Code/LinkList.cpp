#include<iostream>
#include<vector>
#include<algorithm> 
#include<map>
#include<unordered_map>
#include<stdlib.h>
#include<time.h>
using namespace std;
//题目要求单向链表，不使用尾节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

    LinkList(vector<int> nums)
    {
        head = new ListNode;
        dataInput(nums);
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
                cur = cur->next;
            }
        }
    }
    //打印链表
    void printList()
    {
        ListNode* cur = head;
        while(cur != nullptr)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    void swapBehindNodes(ListNode* op)
    {
        //交换两个节点
        if(op->next == nullptr)
        {
            cout << "Can't swap the last node with the next node" <<endl;
            return;
        }
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur != op)
        {
            pre = cur;
            cur = cur->next;
            if(cur == op)
            {
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = cur;
                return;
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

    int size()
    {
        ListNode* cur = head;
        int count = 0;
        while(cur != nullptr)
        {
            count++;
            cur = cur->next;
        }
        return count;
    }

    bool contains(int val)
    {
        ListNode* cur = head;
        while(cur != nullptr)
        {
            if(cur->val == val)
            {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    void addIfNotContains(int val)//函数有一个重载，这个是从头部插入
    {
        if(!contains(val))
        {
            ListNode* insert = new ListNode(val);
            insert->next = head;
            head = insert;
        }
        else
        {
            cout << "The value is already in the list" << endl;
        }
    }

    void addIfNotContains(int val, int tt)//从尾部插入
    {
        ListNode* cur = head;
        while(cur->next != NULL)
        {
            cur = cur->next;
            if(cur->val == val)
            {
                cout << "The value is already in the list" << endl;
                return;
            }
        }
        cur->next = new ListNode(val);
        return;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LinkList linkList(nums);
    //a
    cout << linkList.size() << endl;//根据题目要求，可以输出链表的大小

    //b
    linkList.printList();//根据题目要求，可以输出链表的内容

    //c
    if(linkList.contains(5))//根据题目要求，可以判断链表中是否包含某个值
    {
        cout << "The list contains 5" << endl;
    }
    else
    {
        cout << "The list doesn't contain 5" << endl;
    }
    if(linkList.contains(100))
    {
        cout << "The list contains 100" << endl;
    }
    else
    {
        cout << "The list doesn't contain 100" << endl;
    }
    
    //d
    linkList.addIfNotContains(5);//题目要求，如果链表中已经存在该值，则不插入
    linkList.addIfNotContains(100);//头插
    linkList.addIfNotContains(200, 1);//尾插
    linkList.printList();

    //e
    linkList.deleteNode(10);//题目要求，删除某一值的节点，如果不存在则不删除
    linkList.printList();
}