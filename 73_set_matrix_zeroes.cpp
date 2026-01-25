#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1; // Special flag for the first column

        // Step 1: Traverse the matrix and use the first row/col as markers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    // Mark the i-th row
                    matrix[i][0] = 0;
                    
                    // Mark the j-th column
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0; // Use col0 for the 0th column marker
                }
            }
        }

        // Step 2: Fill the matrix with zeros using markers (excluding 1st row/col)
        // We iterate backwards or skip index 0 to avoid messing up the markers
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle the first row marker
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) matrix[0][j] = 0;
        }

        // Step 4: Handle the first column marker (col0)
        if (col0 == 0) {
            for (int i = 0; i < n; i++) matrix[i][0] = 0;
        }
    }
};