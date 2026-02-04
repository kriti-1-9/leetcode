class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Find the index of the maximum element in the middle column
            int maxRow = 0;
            for (int i = 0; i < m; ++i) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }
            
            // Determine neighbors (handle boundaries with -1)
            int leftVal = (mid > 0) ? mat[maxRow][mid - 1] : -1;
            int rightVal = (mid < n - 1) ? mat[maxRow][mid + 1] : -1;
            
            // If it's greater than both horizontal neighbors, it's a 2D peak
            // (We already know it's greater than its top/bottom neighbors in its column)
            if (mat[maxRow][mid] > leftVal && mat[maxRow][mid] > rightVal) {
                return {maxRow, mid};
            } 
            // If the right neighbor is bigger, move right
            else if (mat[maxRow][mid] < rightVal) {
                low = mid + 1;
            } 
            // Otherwise, move left
            else {
                high = mid - 1;
            }
        }
        
        return {-1, -1};
    }
};