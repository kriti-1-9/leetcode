class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                provinces++;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    for (int neighbor = 0; neighbor < n; ++neighbor) {
                        if (isConnected[curr][neighbor] == 1 && !visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        return provinces;
    }
};