class Solution {
public:
    int nc2(int n) {
        return (n * (n - 1)) / 2;
    }

    void countEdgesAndVertex(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &edgeAndVertex, int parent) {
        if (!vis[node]) {
            vis[node] = 1;
            edgeAndVertex[0] += 1;
        } else {
            return;
        }

        for(auto it: adj[node]) {
            edgeAndVertex[1] += 1;
            countEdgesAndVertex(it, adj, vis, edgeAndVertex, node);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        int count = 0;
        for(int i=0; i<n; ++i) {
            if (!vis[i]) {
                vector<int> edgeAndVertex = {0, 0};
                countEdgesAndVertex(i, adj, vis, edgeAndVertex, -1);
                int vertex = edgeAndVertex[0];
                int edges = edgeAndVertex[1]/2;
                if (edges == nc2(vertex)) {
                    ++count;
                }
            }
        }
        return count;
    }
};