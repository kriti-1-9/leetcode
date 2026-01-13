class Solution {
public:
    vector<vector<int>> adj;

    bool isCycleDFS(int src, vector<bool> &vis, vector<bool> &recPath) {
        vis[src] = true;
        recPath[src] = true;

        for (int v : adj[src]) {
            if (!vis[v]) {
                if (isCycleDFS(v, vis, recPath))
                    return true;
            }
            else if (recPath[v]) {
                return true; // back edge
            }
        }

        recPath[src] = false;
        return false;
    }

    void topoOrder(int src, vector<bool> &vis, stack<int> &s) {
        vis[src] = true;

        for (int v : adj[src]) {
            if (!vis[v]) {
                topoOrder(v, vis, s);
            }
        }

        s.push(src);
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        adj.resize(n);

        // Build graph: b -> a
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> vis(n, false), recPath(n, false);
        vector<int> ans;

        // Cycle detection
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (isCycleDFS(i, vis, recPath)) {
                    return {}; // cycle found
                }
            }
        }

        // Topological sort
        stack<int> s;
        vis.assign(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                topoOrder(i, vis, s);
            }
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};