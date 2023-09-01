#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>> adj) {
  int n = adj.size();
  vector<int> color(n, -1); // -1 indicates not visited
  queue<int> q;

  // Add any vertex to the queue and mark it as visited
  q.push(0);
  color[0] = 0;

  while (!q.empty()) {
    // Dequeue a vertex from the queue
    int u = q.front();
    q.pop();

    // For each of its adjacent vertices
    for (int v : adj[u]) {
      // If the adjacent vertex is not visited, add it to the queue and mark it as visited
      if (color[v] == -1) {
        q.push(v);
        color[v] = 1 - color[u]; // Assign opposite color to the adjacent vertex
      }
      // If the adjacent vertex is already visited and has the same color as the dequeued vertex, then the graph is not bipartite
      else if (color[v] == color[u]) {
        return false;
      }
    }
  }

  // If the above steps do not detect any conflicts, then the graph is bipartite
  return true;
}

int main() {
  // Graph 1 is bipartite
  vector<vector<int>> adj1 = {
    {1, 3},
    {0, 2},
    {1, 3},
    {0, 2}
  };

  // Graph 2 is not bipartite
  vector<vector<int>> adj2 = {
    {1, 2, 3},
    {0, 2, 3},
    {0, 1, 3},
    {0, 1, 2}
  };

  cout << isBipartite(adj1) << endl; // Output: 1 (true)
  cout << isBipartite(adj2) << endl; // Output: 0 (false)

  return 0;
}
