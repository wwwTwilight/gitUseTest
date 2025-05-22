#include<iostream>
#include<vector>
#include<algorithm> 
#include<map>
#include<unordered_map>
#include<stdlib.h>
#include<time.h>
using namespace std;

template<typename T>

class bigHeap
{
private:
    vector<T> HeapV;
public:

    bigHeap()
    {
        HeapV.push_back(0);
    }

    void heapInsert(T val)
    {
        HeapV.push_back(val);
        shiftUP();
    }

    void heapDelete()
    {
        if(HeapV.size() == 1)
        {
            return;
        }
        swap(HeapV[1], HeapV[HeapV.size()-1]);
        HeapV.erase(HeapV.end() - 1);
        shiftDown();
    }

    void shiftUP()
    {
        int index = HeapV.size() - 1;
        while(index / 2 > 0 && HeapV[index] > HeapV[index/2])
        {
            swap(HeapV[index], HeapV[index/2]);
            index /= 2;
        }
    }

    void shiftDown()
    {
        int index = 1;
        while(index < (HeapV.size() / 2) && (HeapV[index] < HeapV[index * 2] || HeapV[index] < HeapV[index * 2 + 1]))
        {
            if(HeapV[index * 2 + 1] < HeapV[index * 2])
            {
                swap(HeapV[index], HeapV[index * 2]);
                index *= 2;
            }
            else if(HeapV[index * 2] < HeapV[index * 2 + 1])
            {
                swap(HeapV[index], HeapV[index * 2 + 1]);
                index = index * 2 + 1;
            }
        }
    }

    T getTop()
    {
        return HeapV[1];
    }

    vector<T> returnHeap()
    {
        return HeapV;
    }

    void print()
    {
        for(int i = 1; i < HeapV.size(); i++)
        {
            cout<<HeapV[i]<<" ";
        }
        cout<<endl;
    }

    void HeapSort()
    {
        vector<T> res = HeapV;
        if(res.size() == 1)
        {
            return;
        }
        while(res.size() > 1)
        {
            cout << res[1] << ' ';
            swap(res[1], res[res.size()-1]);
            res.erase(res.end() - 1);
            int index = 1;
            while(index * 2 <= (res.size() / 2) && (res[index] < res[index * 2] || res[index] < res[index * 2 + 1]))
            {
                if(res[index * 2 + 1] < res[index * 2])
                {
                    swap(res[index], res[index * 2]);
                    index *= 2;
                }
                else if(res[index * 2] < res[index * 2 + 1])
                {
                    swap(res[index], res[index * 2 + 1]);
                    index = index * 2 + 1;
                }
            }
        }
    }
};

template<typename T>

class smallHeap
{
private:
    vector<T> HeapV;
public:

    smallHeap()
    {
        HeapV.push_back(0);
    }

    smallHeap(vector<T> input)
    {
        HeapV.push_back(0);
        for(auto i : input)
        {
            HeapV.push_back(i);
        }
        int index = HeapV.size() / 2;
        while(index > 0)
        {
            shiftDown(index);
            index--;
        }
    }

    void heapInsert(T val)
    {
        HeapV.push_back(val);
        shiftUP(HeapV.size() - 1);
    }

    void heapDelete()
    {
        if(HeapV.size() == 1)
        {
            return;
        }
        swap(HeapV[1], HeapV[HeapV.size() - 1]);
        HeapV.erase(HeapV.end() - 1);
        shiftDown();
    }

    void shiftUP(int index)
    {
        while(index / 2 > 0 && HeapV[index] < HeapV[index/2])
        {
            swap(HeapV[index], HeapV[index/2]);
            index /= 2;
        }
    }

    void shiftDown(int index = 1)
    {
        int size = HeapV.size();
        while (index * 2 < size)
        {
            int smallerChild = index * 2;
            if (smallerChild + 1 < size && HeapV[smallerChild + 1] < HeapV[smallerChild])
            {
                smallerChild = smallerChild + 1;
            }

            if (HeapV[index] <= HeapV[smallerChild])
            {
                break;
            }
            swap(HeapV[index], HeapV[smallerChild]);
            index = smallerChild;
        }
    }

    T getTop()
    {
        return HeapV[1];
    }

    vector<T> returnHeap()
    {
        return HeapV;
    }

    void print()
    {
        for(int i = 1; i < HeapV.size(); i++)
        {
            cout<<HeapV[i]<<" ";
        }
        cout<<endl;
    }

    void HeapSort()
    {
        vector<T> temp = HeapV;
        if(HeapV.size() == 1)
        {
            return;
        }
        while(HeapV.size() > 1)
        {
            //cout << HeapV[1] << ' ';
            swap(HeapV[1], HeapV[HeapV.size()-1]);
            HeapV.erase(HeapV.end() - 1);
            shiftDown();
            print();
        }
        for(int i = 1; i < temp.size(); i++)
        {
            HeapV.push_back(temp[i]);
        }
        cout<<endl;
    }
};

int main()
{
    smallHeap<int> H;
    vector<int> test = {142, 543, 123, 65, 453, 879, 572, 434, 111, 242, 811, 102};
    // H.heapInsert(142);
    // H.heapInsert(543);
    // H.heapInsert(123);
    // H.heapInsert(65);
    // H.heapInsert(453);
    // H.heapInsert(879);
    // H.heapInsert(572);
    // H.heapInsert(434);
    // H.heapInsert(111);
    // H.heapInsert(242);
    // H.heapInsert(811);
    // H.heapInsert(102);
    // H.print();
    // H.HeapSort();
    // H.print();
    smallHeap<int> T(test);
    T.print();
    T.HeapSort();
    T.print();
}