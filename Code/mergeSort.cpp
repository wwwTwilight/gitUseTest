#include<iostream>
#include<vector>
#include<algorithm> 
#include<map>
#include<unordered_map>
#include<stdlib.h>
#include<time.h>
using namespace std;

void merge(vector<int> &v, int l, int mid, int r); // 合并两个有序数组
void printV(vector<int> &v); // 打印数组

void process(vector<int> &v, int l, int r)
{
    if(l == r)
    {
        return;
    }
    int mid = l + ((r - l) >> 1);
    process(v, l, mid);
    process(v, mid + 1, r);
    merge(v, l, mid, r);
}

void merge(vector<int> &v, int l, int mid, int r)
{
    vector<int> temp;
    int i = l, j = mid + 1;
    while(i <= mid && j <= r)
    {
        if(v[i] <= v[j])
        {
            temp.push_back(v[i]);
            i++;
        }
        else
        {
            temp.push_back(v[j]);
            j++;
        }
    }
    while(i <= mid)
    {
        temp.push_back(v[i]);
        i++;
    }
    while(j <= r)
    {
        temp.push_back(v[j]);
        j++;
    }
    for(int i = 0; i < temp.size(); i++)
    {
        v[l + i] = temp[i];
    }
    // printV(temp);
    // printV(v);
}

void printV(vector<int> &v)
{
    for(auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {66, 72, 38, 65, 28, 96, 27, 5, 24, 88, 14, 50, 94, 40, 54, 22, 98, 95, 78, 45, 9, 35, 21, 1, 56, 53, 71, 92, 10, 26, 64, 62, 34, 41, 15, 81, 17, 58, 76, 39, 3, 100, 7, 82, 31, 73, 32, 48, 86, 68, 67, 23, 91, 43, 83, 42, 37, 19, 18, 33, 20, 44, 87, 47, 12, 51, 11, 77, 52, 80, 85, 59, 70, 16, 69, 55, 90, 89, 49, 36, 79, 61, 97, 8, 84, 60, 57, 29, 75, 46, 13, 93, 74, 99, 63, 2, 4, 30, 25, 6};
    process(v, 0, v.size() - 1);
    printV(v);
}