#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:
    vector<vector<int>> graph;
    int length;

    Graph(int length)
    {
        this->length = length;
        graph.resize(length);
    }

    void addEdge(int u, int v);
    void print();
};

void Graph::addEdge(int u, int v)
{
    if (graph.empty())
        return;
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void Graph::print()
{
    for (unsigned int i = 0; i < graph.size(); ++i)
    {
        cout << "Adjacency list of vertex " << i << endl;
        cout << i;
        for (auto x : graph[i])
            cout << " -> " << x;
        cout << endl
             << endl;
    }
}

int main()
{
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.print();

    system("pause");

    return 0;
}