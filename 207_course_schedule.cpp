class Solution {
public:
    bool dfs(int src, vector<int>& state, const vector<vector<int>>& adj) {
        // state: 0 = unvisited, 1 = visiting, 2 = visited
        state[src] = 1; // mark as visiting

        for (int v : adj[src]) {
            if (state[v] == 0) {
                if (dfs(v, state, adj)) {
                    return true; // cycle found
                }
            } else if (state[v] == 1) {
                // back edge -> cycle
                return true;
            }
        }

        state[src] = 2; // mark as fully visited
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // build adjacency list: pre -> course
        vector<vector<int>> adj(n);
        for (auto &e : prerequisites) {
            int course = e[0];
            int pre = e[1];
            adj[pre].push_back(course);
        }

        vector<int> state(n, 0); // 0 = unvisited

        for (int i = 0; i < n; ++i) {
            if (state[i] == 0) {
                if (dfs(i, state, adj)) {
                    return false; // cycle detected
                }
            }
        }
        return true; // no cycle
    }
};