#include<bits/stdc++.h>
using namespace std;

// Adjacency List
vector<vector<int>> adj;

// Function to add edge u --> v
void addEdge(int u, int v){
    adj[u].push_back(v);
}
// Helper function to check for cycle.
bool checkCycleUtil (int node, 
            bool *visited, bool *inStack){
    // Check if node exists in the
    // recursive stack.
    if (inStack[node])
        return true;
    
    // Check if node is already visited.
    if (visited[node])
        return false;
    
    // Marking node as visited.
    visited[node] = true;

    // Marking node to be present in
    // recursive stack.
    inStack[node] = true;

    // Iterate for all adjacent of 
    // 'node'.
    for (int v : adj[node]){
        // Recurse for 'v'.
        if (checkCycleUtil(v, visited, inStack))
            return true;
    }

    // Mark 'node' to be removed
    // from the recursive stack.
    inStack[node] = false;

    // Return false if no cycle exists.
    return false;
}
// Function to check for the cycle.
bool checkCycle(int V, int E){
    // Defining visited and inStack array
    // to keep track of visited vertices 
    // and vertices in Recursive stack. 
    bool visited[V]; 
    bool inStack[V]; 
    for(int i = 0; i < V; i++){
        visited[i] = false;
        inStack[i] = false;
    }
    
    // Iterating for i = 0 To i = V - 1
    // to detect cycle in different 
    // DFS trees. 
    for (int i = 0; i < V; i++){
        // Check if cycle exists.
        if (checkCycleUtil(i, visited, inStack)){
            return true;
        }
    }
    // Returning false, if no cycle is found.
    return false;

}
int main(){
    // Defining the number of Vertices
    // and the number of edges. 
    int V = 5, E = 7;

    // Defining Adjacency List
    adj.resize(V);
    // Building the Graph same as example 1.
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(4, 1);
    addEdge(4, 2);

    // If the graph contains cycle 
    // Print YES
    if(checkCycle(V, E))
        cout << "YES\n";
    // Otherwise Print NO
    else
        cout << "NO\n";
}
