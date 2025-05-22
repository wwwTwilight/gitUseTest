#include<iostream>
#include<vector>
#include<algorithm> 
#include<map>
#include<unordered_map>
#include<stdlib.h>
#include<time.h>
using namespace std;
//题目要求给定两个数组，找出它们的交集，其中已知数组是有序的
int main()
{
    vector<int> L1 = {1,2,5,7,9,14,16,19,20,25,26,28,35,37,40,42,45,47,49,50};
    vector<int> L2 = {1,3,5,6,8,14,17,19,24,26,28,31,32,35,40,43,45,46,49,50};
    vector<int> res;
    int ptr1 = 0, ptr2 = 0;
    while(ptr1 < L1.size() && ptr2 < L2.size())
    {
        if(L1[ptr1] == L2[ptr2])
        {
            res.push_back(L1[ptr1]);
            ptr1++;
            ptr2++;
        }
        if(L1[ptr1] < L2[ptr2])
        {
            ptr1++;
        }
        if(L1[ptr1] > L2[ptr2])
        {
            ptr2++;
        }
    }
    cout << "交集是：";
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}