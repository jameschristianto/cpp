#include <iostream>
#include <list>

using namespace std;

class Graph{
public:
    list<int> *graph;
    int size;
    
    Graph(int size){
        this->size = size;
        graph = new list<int>[size];
    }
    
    void insert(int u, int v){
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    void print(){
        for(int i = 0; i < size; i++){
            cout << i;
            for(int j : graph[i]){
                cout << " -> " << j;
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(6);
    
    g.insert(0, 1);
    g.insert(0, 3);
    g.insert(2, 1);
    g.insert(3, 1);
    g.insert(3, 2);
    g.insert(3, 4);
    g.insert(5, 4);
    
    g.print();

    system("pause");

    return 0;
}
