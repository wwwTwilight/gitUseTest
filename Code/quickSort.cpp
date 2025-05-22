#include<iostream>
#include<vector>
#include<algorithm> 
#include<map>
#include<unordered_map>
#include<stdlib.h>
#include<time.h>
using namespace std;

void printV(vector<int> &v);

void quickSort(vector<int> &v, int l, int r)
{
    if(l >= r)
    {
        //cout << "end this" << endl;
        return;
    }
    swap(v[l + ((r - l) >> 1)], v[r]);
    // cout << "start : ";
    // printV(v);
    int i = l, j = r;
    int pivot = v[r];
    while(i < j)
    {
        while(v[i] < pivot && i < j)
        {
            i++;
        }

        while(v[j] >= pivot && i < j)
        {
            j--;
        }
        swap(v[i], v[j]);
        // cout << "i = " << i << " j = " << j << endl;
        // printV(v);
    }
    swap(v[i], v[r]);
    printV(v);
    quickSort(v, l, i - 1);
    quickSort(v, i + 1, r);
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
    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    quickSort(v, 0, v.size() - 1);
    printV(v);
}