#include<iostream>
#include<vector>
#include<algorithm> 
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<stdlib.h>
#include<time.h>
#include<stack>
using namespace std;

const int infinity = INT_MAX - 1000; //定义无限的大小

class Edge //定义边的数据类型，需要包含边的距离和时间以及目的地
{
    public:
    int timeCost;
    int distance;
    int to;

    Edge(int timeCost,int distance,int to)
    {
        this->timeCost = timeCost;
        this->distance = distance;
        this->to = to;
    }
};

class Graph
{
    private:
    int V;//代表节点个数
    vector<vector<Edge>> adj;//邻接表
    public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }
    
    void addEdge(int from,int to,int timeCost,int distance)
    {
        adj[from].push_back(Edge(timeCost,distance,to));
        //根据题目要求，应该是一个无向图，所以应该双向添加边
        adj[to].push_back(Edge(timeCost,distance,from));
    }

    void DijstraResult(vector<int> v, vector<vector<int>> D)
    {
        for(int i = 0; i < v.size(); i++)
        {
            cout << "到节点" << i << "最短距离为:";
            if(v[i] == infinity)
            {
                cout << "不可达";
            }
            else
            {
                cout << v[i] << " ";
                cout << "路径：";
                for(int j = 0; j < D[i].size(); j++)
                {
                    cout << "->" << D[i][j];
                }
            }
            cout << endl;
        }
    }

    void PathDijstra(int start)
    {
        unordered_map<int, int> confirmV;//已经确定最小路径的节点
        vector<int> minPath(V, infinity);//从起点到该节点的最短路径
        minPath[start] = 0;
        vector<vector<int>> minPathD(V);//从起点到该节点的最短路径节点集
        minPathD[start] = {start};
        for(int i = 0; confirmV.size() < V && i < V; i++)//这步是在找最小的节点
        {
            int minIndex = minInVectorIndex(minPath, confirmV);
            confirmV[minIndex] = 1;//已经确定最小路径的节点
            for(auto v : adj[minIndex])//这步是在更新相邻的节点
            {
                if(!confirmV.contains(v.to) && minPath[v.to] > minPath[minIndex] + v.distance)
                {
                    minPath[v.to] = minPath[minIndex] + v.distance;
                    minPathD[v.to] = minPathD[minIndex];
                    minPathD[v.to].push_back(v.to);
                }
            }
        }

        cout << start << "到各个点的最短距离：" << endl;

        DijstraResult(minPath, minPathD);

        cout << endl;
    }

    void TimeDijstra(int start)
    {
        unordered_map<int, int> confirmV;//已经确定最小路径的节点
        vector<int> minTime(V, infinity);//从起点到该节点的最短时间
        minTime[start] = 0;
        vector<vector<int>> minTimeD(V);//从起点到该节点的最短时间节点集
        minTimeD[start] = {start};
        for(int i = 0; confirmV.size() < V && i < V; i++)//这步是在找最小的节点
        {
            int minIndex = minInVectorIndex(minTime, confirmV);
            confirmV[minIndex] = 1;//已经确定最小路径的节点
            for(auto v : adj[minIndex])//这步是在更新相邻的节点
            {
                if(!confirmV.contains(v.to) && minTime[v.to] > minTime[minIndex] + v.timeCost)
                {
                    minTime[v.to] = minTime[minIndex] + v.timeCost;
                    minTimeD[v.to] = minTimeD[minIndex];
                    minTimeD[v.to].push_back(v.to);
                }
            }
        }
        
        cout << start << "到各个点的最短时间：" << endl;

        DijstraResult(minTime, minTimeD);

        cout << endl;
    }

    void shortestPath(vector<int> destination)
    {
        vector<int> shortestPath;
        int shortestPathLength = 0;
        for(int i = 0; i < destination.size() - 1; i++)
        {
            unordered_map<int, int> confirmV;//已经确定最小路径的节点
            vector<int> minPath(V, infinity);//从起点到该节点的最短路径
            minPath[destination[i]] = 0;
            vector<vector<int>> minPathD(V);//从起点到该节点的最短路径节点集
            minPathD[destination[i]] = {destination[i]};
            for(int i = 0; confirmV.size() < V && i < V; i++)//这步是在找最小的节点
            {
                int minIndex = minInVectorIndex(minPath, confirmV);
                confirmV[minIndex] = 1;//已经确定最小路径的节点
                for(auto v : adj[minIndex])//这步是在更新相邻的节点
                {
                    if(!confirmV.contains(v.to) && minPath[v.to] > minPath[minIndex] + v.distance)
                    {
                        minPath[v.to] = minPath[minIndex] + v.distance;
                        minPathD[v.to] = minPathD[minIndex];
                        minPathD[v.to].push_back(v.to);
                    }
                }
            }
            if(minPath[destination[i + 1]] == infinity)
            {
                cout << "无法到达" << destination[i + 1] << endl;
                return;
            }
            shortestPathLength += minPath[destination[i + 1]];

            for(int j = 1; j < minPathD[destination[i + 1]].size(); j++)
            {
                shortestPath.push_back(minPathD[destination[i + 1]][j]);
            }
                
        }

        cout << "途经{ " ;
        for(int i = 0; i < destination.size(); i++)
        {
            cout << destination[i] << " ";
        }

        cout << "}的最短距离路径:" << shortestPathLength << " : ";
        cout << "->" << destination[0];
        for(int i = 0; i < shortestPath.size(); i++)
        {
            cout << "->" << shortestPath[i];
        }  
        cout << endl; 
    }

    void shortestTime(vector<int> destination)
    {
        vector<int> shortestTime;
        int shortestTimeLength = 0;
        for(int i = 0; i < destination.size() - 1; i++)
        {
            unordered_map<int, int> confirmV;//已经确定最小路径的节点
            vector<int> minTime(V, infinity);//从起点到该节点的最短路径
            minTime[destination[i]] = 0;
            vector<vector<int>> minTimeD(V);//从起点到该节点的最短路径节点集
            minTimeD[destination[i]] = {destination[i]};
            for(int i = 0; confirmV.size() < V && i < V; i++)//这步是在找最小的节点
            {
                int minIndex = minInVectorIndex(minTime, confirmV);
                confirmV[minIndex] = 1;//已经确定最小路径的节点
                for(auto v : adj[minIndex])//这步是在更新相邻的节点
                {
                    if(!confirmV.contains(v.to) && minTime[v.to] > minTime[minIndex] + v.timeCost)
                    {
                        minTime[v.to] = minTime[minIndex] + v.timeCost;
                        minTimeD[v.to] = minTimeD[minIndex];
                        minTimeD[v.to].push_back(v.to);
                    }
                }
            }
            if(minTime[destination[i + 1]] == infinity)
            {
                cout << "无法到达" << destination[i + 1] << endl;
                return;
            }
            shortestTimeLength += minTime[destination[i + 1]];

            for(int j = 1; j < minTimeD[destination[i + 1]].size(); j++)
            {
                shortestTime.push_back(minTimeD[destination[i + 1]][j]);
            }
                
        }

        cout << "途经{ " ;
        for(int i = 0; i < destination.size(); i++)
        {
            cout << destination[i] << " ";
        }

        cout << "}的最短时间路径:" << shortestTimeLength << " : ";
        cout << "->" << destination[0];
        for(int i = 0; i < shortestTime.size(); i++)
        {
            cout << "->" << shortestTime[i];
        }
        cout << endl;   
    }

    int minInVectorValue(vector<int> v, unordered_map<int, int> confirmV)
    {
        return findMin(v, confirmV, false);
    }

    int minInVectorIndex(vector<int> &v, unordered_map<int, int> &confirmV)
    {
        return findMin(v, confirmV, true);
    }

    int findMin(vector<int> &v, unordered_map<int, int> &confirmV, bool choose)//最后一个参数，true是返回索引，false是返回值
    {
        int min = INT_MAX;
        int index = 0;
        for(int i = 0; i < v.size(); i++)
        {
            if(confirmV.contains(i))
            {
                continue;
            }
            else if(v[i] < min)
            {
                min = v[i];
                index = i;
            }
        }
        if(choose)
        {
            return index;
        }
        else
        {
            return min;
        }
    }

    void DFS(vector<int> &confirmV, int vertex)
    {
        confirmV[vertex] = 1;
        cout << vertex << " ";
        vector<Edge> nextNode = adj[vertex];
        for(auto v : nextNode)
        {
            if(confirmV[v.to] == 1)
            {
                continue;
            }
            DFS(confirmV,v.to);
        }
    }

    void BFS(vector<int> &confirmV, int vertex, queue<int> &Q)
    {
        confirmV[vertex] = 1;
        cout << vertex << " ";
        Q.pop();
        vector<Edge> nextNode = adj[vertex];
        for(auto v : nextNode)
        {
            if(confirmV[v.to] == 1)
            {
                continue;
            }
            Q.push(v.to);
            confirmV[v.to] = 1;
        }
        if(!Q.empty())
        {
            BFS(confirmV,Q.front(),Q);
        }
        
    }

    void print()//DFS输出
    {
        vector<int> confirmV(V, 0);
        for(int i = 0; i < V; i++)
        {
            if(confirmV[i] == 1)
            {
                continue;
            }
            else
            {
                cout << "| ";
                DFS(confirmV, i);
            }
        }
        cout << endl;
    }

    void print(int i)//BFS输出
    {
        queue<int> Q;
        vector<int> confirmV(V, 0);
        for(int i = 0; i < V; i++)
        {
            if(confirmV[i] == 1)
            {
                continue;
            }
            else
            {
                Q.push(i);
                cout << "| ";
                BFS(confirmV, Q.front(), Q);
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph g(14);
    //addEdge参数：from,to,timeCost,distance
    g.addEdge(0,1,4,3);
    g.addEdge(0,2,5,4);
    g.addEdge(1,2,3,2);
    g.addEdge(1,3,3,3);
    g.addEdge(1,4,5,4);
    g.addEdge(2,5,10,2);
    g.addEdge(4,5,4,3);
    g.addEdge(4,13,2,3);
    g.addEdge(4,12,3,4);
    g.addEdge(5,12,5,5);

    g.addEdge(6,7,3,4);
    g.addEdge(6,8,2,2);
    g.addEdge(7,9,2,3);
    g.addEdge(7,10,7,4);
    g.addEdge(7,11,1,10);
    g.addEdge(8,9,5,2);
    g.addEdge(10,11,5,4);

    g.PathDijstra(0);
    g.TimeDijstra(0);
    g.PathDijstra(6);
    g.TimeDijstra(6);

    vector<int> path1 = {0, 2, 13};
    g.shortestPath(path1);
    g.shortestTime(path1);
    vector<int> path2 = {6, 11, 7, 8};
    g.shortestPath(path2);
    g.shortestTime(path2);
}