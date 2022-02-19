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

        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {
                graph[i].resize(length);
            }
        }
    }

    void addEdge(int u, int v);
    void print();
};

void Graph::addEdge(int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}


void Graph::print()
{
    cout << "  ";
    for (int i = 0; i < length; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < length; i++)
    {
        cout << i << " ";
        for (int j = 0; j < length; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
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