class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // 1. Quick check for impossible case
        // Using long long for total needed to avoid overflow
        if ((long long)m * k > bloomDay.size()) return -1;

        int low = 1, high = 1e9; // 1e9 is the max possible bloomDay per constraints
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1; // Try to find a smaller day
            } else {
                low = mid + 1;  // Need more days
            }
        }
        return ans;
    }

private:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;

        for (int b : bloomDay) {
            if (b <= day) {
                flowers++; // This flower has bloomed
                if (flowers == k) {
                    bouquets++;
                    flowers = 0; // Reset for the next adjacent set
                }
            } else {
                flowers = 0; // Not bloomed, break the adjacency
            }
            
            if (bouquets >= m) return true; // Optimization
        }
        return bouquets >= m;
    }
};