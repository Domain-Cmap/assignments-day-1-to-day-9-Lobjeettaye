class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        vector<int> bfsResult;
        vector<bool> visited(adj.size(), false);
        queue<int> q;

        // Start BFS from node 0
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfsResult.push_back(node);

            // Traverse all adjacent nodes
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return bfsResult;
    }
};
