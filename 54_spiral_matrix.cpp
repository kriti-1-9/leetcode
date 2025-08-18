class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;
    vector<int> ans;
    
    while (srow <= erow && scol <= ecol) {
        // Traverse the top row
        for (int j = scol; j <= ecol; j++) {
            ans.push_back(matrix[srow][j]);
        }
        srow++;
        
        // Traverse the right column
        for (int i = srow; i <= erow; i++) {
            ans.push_back(matrix[i][ecol]);
        }
        ecol--;
        
        // Traverse the bottom row (if not already traversed)
        if (srow <= erow) {
            for (int j = ecol; j >= scol; j--) {
                ans.push_back(matrix[erow][j]);
            }
            erow--;
        }
        
        // Traverse the left column (if not already traversed)
        if (scol <= ecol) {
            for (int i = erow; i >= srow; i--) {
                ans.push_back(matrix[i][scol]);
            }
            scol++;
        }
    }
    return ans;
}
};