#include<iostream>
#include<vector>
#include<algorithm> 
#include<map>
#include<unordered_map>
#include<stdlib.h>
#include<time.h>
using namespace std;

struct v2
{
    int parent;
    int rank;
    v2(int n = 0, int r = 0)
    {
        parent = n;
        rank = r;
    }
};

class DisjointSet
{
private:
    vector<v2> a;
public:
    DisjointSet()
    {
        v2 init(0, 0);// 首个是空的，不然后面不好写
        a.push_back(init);
    }

    int find(int n)
    {
        int temp = n;
        while(a[n].parent != 0)
        {
            n = a[n].parent;
        }
        while(a[temp].parent != 0)
        {
            a[temp].parent = n;
            temp = a[temp].parent;
        }
        return n;
    }

    void Union(int n1, int n2)
    {
        int p1 = find(n1);
        int p2 = find(n2);
        if(p1 == p2)
        {
            return;
        }
        else
        {
            if(a[p1].rank >= a[p2].rank)
            {
                // a[p2].parent = p1;
                // a[p1].rank += a[p2].rank;
                // a[p2].rank = 0;
                int ptr1 = n2;
                int ptr2 = n2;
                a[p1].rank += a[p2].rank;
                while(ptr1 != 0)
                {
                    ptr1 = a[ptr1].parent;
                    a[ptr2].parent = p1;
                    a[ptr2].rank = 0;
                    ptr2 = ptr1;
                }
            }
            else if(a[p1].rank < a[p2].rank)
            {
                // a[p1].parent = p2;
                // a[p2].rank += a[p1].rank;
                // a[p1].rank = 0;
                int ptr1 = n1;
                int ptr2 = n1;
                a[p2].rank += a[p1].rank;
                while(ptr1 != 0)
                {
                    ptr1 = a[ptr1].parent;
                    a[ptr2].parent = p2;
                    a[ptr2].rank = 0;
                    ptr2 = ptr1;
                }
            }
        }
    }

    void addNew()
    {
        a.push_back(v2(0, 1));
    }

    void print()
    {
        for(int i = 1; i < a.size(); i++)
        {
            cout << i << "->" << a[i].parent << " " << a[i].rank << endl;
        }
    }
};

int main()
{
    DisjointSet d;
    d.addNew();
    d.addNew();
    d.addNew();
    d.addNew();
    d.addNew();
    d.addNew();
    d.addNew();
    d.addNew();
    d.addNew();
    // cout << d.find(1) << endl;
    // d.print();
    // cout << "-------" << endl;
    d.Union(1, 2);
    d.Union(3, 4);
    d.Union(5, 6);
    d.Union(1, 7);
    d.Union(1, 3);
    d.print();
}