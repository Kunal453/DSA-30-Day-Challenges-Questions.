#include <iostream>
#include <vector>
using namespace std;

bool isBipartite(vector<vector<int>> adj, int n) {
  vector<int> color(n, -1);
  bool bipartite = true;

  for (int i = 0; i < n; i++) {
    if (color[i] == -1) {
      color[i] = 0;
      queue<int> q;
      q.push(i);

      while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
          if (color[v] == -1) {
            color[v] = (color[u] + 1) % 2;
            q.push(v);
          } else if (color[v] == color[u]) {
            bipartite = false;
            break;
          }
        }

        if (!bipartite) break;
      }
    }
  }

  return bipartite;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bool bipartite = isBipartite(adj, n);
  if (bipartite) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
