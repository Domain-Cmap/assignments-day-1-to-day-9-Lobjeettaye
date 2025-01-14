class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int V = adj.size(); // Number of vertices
        vector<int> result;
        vector<bool> visited(V, false);
        
        // Helper function for DFS traversal
        function<void(int)> dfsHelper = [&](int node) {
            visited[node] = true; // Mark the node as visited
            result.push_back(node); // Add it to the result
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    dfsHelper(neighbor); // Recursively visit unvisited neighbors
                }
            }
        };
        
        // Perform DFS starting from node 0
        dfsHelper(0);
        return result;
    }
};
