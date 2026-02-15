class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();

        // Step 1: Traverse the boundary (first and last rows/cols)
        for (int i = 0; i < n; i++) {
            // First column
            if (board[i][0] == 'O') dfs(i, 0, board);
            // Last column
            if (board[i][m - 1] == 'O') dfs(i, m - 1, board);
        }

        for (int j = 0; j < m; j++) {
            // First row
            if (board[0][j] == 'O') dfs(0, j, board);
            // Last row
            if (board[n - 1][j] == 'O') dfs(n - 1, j, board);
        }

        // Step 2 & 3: Flip 'O' to 'X' (surrounded) and '#' back to 'O' (safe)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }

private:
    void dfs(int r, int c, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Boundary check and condition check
        if (r < 0 || r >= n || c < 0 || c >= m || board[r][c] != 'O') return;

        // Mark as "Safe"
        board[r][c] = '#';

        // Explore neighbors
        dfs(r + 1, c, board);
        dfs(r - 1, c, board);
        dfs(r, c + 1, board);
        dfs(r, c - 1, board);
    }
};