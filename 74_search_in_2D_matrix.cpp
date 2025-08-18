class Solution {
public:
    bool searchinrow(vector<vector<int>> &mat, int target, int row) {
        int n = mat[0].size(); 
        int st = 0, end = n-1;
        while(st <= end) {
            int mid = st+(end-st)/2;
            if(target == mat[row][mid]) {
                return true;
            }
            else if(target > mat[row][mid]) {
                st  = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int startrow = 0, endrow = m-1;
        while( startrow <= endrow) {
            int midrow = startrow + (endrow - startrow)/2;
            if(target >= matrix[midrow][0] && target <= matrix[midrow][n-1]) {
                return searchinrow(matrix, target, midrow);
            }
            else if(target >= matrix[midrow][n-1]) {
                startrow = midrow+1;
            }
            else{
                endrow = midrow-1; 
            }
        }
        return false;
    }
};