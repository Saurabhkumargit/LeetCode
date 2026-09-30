// https://leetcode.com/problems/redundant-connection/

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto& edge : edges) {
            int u = edge[0];AA
            int v = edge[1];

            vector<bool> visited(n + 1, false);
            queue<int> q;

            q.push(u);
            visited[u] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                if (node == v)
                    return edge;

                for (int nei : adj[node]) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};