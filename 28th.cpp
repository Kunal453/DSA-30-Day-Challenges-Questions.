#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For an undirected graph
    }

    // Function to check if the graph is bipartite
    bool isBipartite() {
        vector<int> color(V, -1); // Initialize colors to -1 (unassigned)
        
        for (int start = 0; start < V; ++start) {
            if (color[start] == -1) { // If the current component is unvisited
                queue<int> q;
                q.push(start);
                color[start] = 0; // Assign the color 0 to the starting node

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v : adj[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u]; // Assign the opposite color
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return false; // The graph is not bipartite
                        }
                    }
                }
            }
        }
        
        return true; // If no conflict was found, the graph is bipartite
    }
};

int main() {
    // Create a graph with 4 vertices
   
