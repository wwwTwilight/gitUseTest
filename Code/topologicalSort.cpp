#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;
class Graph 
{
    int V;
    list<int> *adj;

public:
    Graph(int V) 
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) 
    {
        adj[v].push_back(w); // v->w
    }

    void topologicalSort() 
    {
        vector<int> inDegree(V, 0);

        for (int u = 0; u < V; u++) 
        {
            list<int>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                inDegree[*i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty()) 
        {
            int u = q.front();
            q.pop();
            cout << u << " ";
            list<int>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            {
                if (--inDegree[*i] == 0)
                {
                    q.push(*i);
                }
            }
            count++;
        }
        if (count != V) 
        {
            cout << "图中有环存在，无法进行拓扑排序" << endl;
            return;
        }
    }
};



int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();
    return 0;
}
