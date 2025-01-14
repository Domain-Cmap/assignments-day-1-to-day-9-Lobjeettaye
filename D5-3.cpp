class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size(); // Number of vertices
        vector<bool> visited(V, false);
        
        // Helper function for DFS traversal
        function<bool(int, int)> dfsHelper = [&](int node, int parent) {
            visited[node] = true; // Mark the node as visited
            
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    // If the neighbor is not visited, recursively visit it
                    if (dfsHelper(neighbor, node)) {
                        return true;
                    }
                } else if (neighbor != parent) {
                    // If the neighbor is visited and is not the parent, a cycle is detected
                    return true;
                }
            }
            return false;
        };
        
        // Check for cycles in each component of the graph
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsHelper(i, -1)) {
                    return true;
                }
            }
        }
        
        return false; // No cycle found
    }
};
