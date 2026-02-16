class Solution {
public:
    // Helper function to perform BFS for a single component
    bool check(int start, int V, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it : graph[node]) {
                // If the adjacent node is not yet colored
                if(color[it] == -1) {
                    color[it] = !color[node]; // Assign opposite color
                    q.push(it);
                }
                // If it is colored and has the same color as the current node
                else if(color[it] == color[node]) {
                    return false; // Found an odd-cycle!
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1); // -1 means uncolored

        // Loop through all nodes to handle disconnected components
        for(int i = 0; i < V; i++) {
            if(color[i] == -1) {
                if(check(i, V, graph, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};