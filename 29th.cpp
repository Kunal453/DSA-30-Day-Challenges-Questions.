#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *adj;

    bool isCyclicUtil(int v, bool visited[], bool *recStack) {
        if (visited[v] == false) {
            visited[v] = true;
            recStack[v] = true;

            for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
                if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
                    return true;
                else if (recStack[*i])
                    return true;
            }
        }
        recStack[v] = false;
        return false;
    }

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    bool isCyclic() {
        bool *visited = new bool[V];
        bool *recStack = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
            recStack[i] = false;
        }

        for (int i = 0; i < V; i++) {
            if (isCyclicUtil(i, visited, recStack))
                return true;
        }

        return false;
    }
};

int main() {
    Graph g(4); // Create a graph with 4 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if (g.isCyclic())
        cout << "Graph contains a cycle." << endl;
    else
        cout << "Graph does not contain a cycle." << endl;

    return 0;
}
