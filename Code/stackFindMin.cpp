#include<iostream>
#include<vector>
#include<algorithm> 
#include<map>
#include<unordered_map>
#include<stdlib.h>
#include<time.h>
#include<stack>
using namespace std;
//题目要求提出一个与栈相似的数据结构，其中要包括一个方法，能够实现找到栈中的最小元素，且时间复杂度为O(1)
class Mystack
{
private:
    stack <int> oriStack;
    stack <int> minStack;
public:
    Mystack(){}
    void push(int x)
    {
        oriStack.push(x);
        if(minStack.empty() || minStack.top() >= x)
        {
            minStack.push(x);
        }
    }

    void pop()
    {
        if(oriStack.empty())
        {
            return;
        }
        if(minStack.top() == oriStack.top())
        {
            minStack.pop();
        }
        oriStack.pop();
    }

    int findMin()
    {
        if (!minStack.empty()) 
        {
            return minStack.top();
        }
        else
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }

    int top()
    {
        if(oriStack.empty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        else
        {
            return oriStack.top();
        }
    }
};

int main()
{
    Mystack ms;
    ms.push(1);
    ms.push(3);
    ms.push(4);
    ms.push(6);
    ms.push(1);
    ms.pop();
    cout << ms.findMin() << endl;
}
