class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0;
        for (int w : weights) {
            low = max(low, w);   // Smallest capacity is the heaviest single package
            high += w;           // Largest capacity is the total weight
        }
        
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canShip(weights, days, mid)) {
                ans = mid;
                high = mid - 1; // Try to find a smaller capacity
            } else {
                low = mid + 1;  // Increase capacity
            }
        }
        return ans;
    }

private:
    bool canShip(vector<int>& weights, int daysLimit, int capacity) {
        int daysNeeded = 1;
        int currentLoad = 0;
        
        for (int w : weights) {
            if (currentLoad + w > capacity) {
                daysNeeded++;
                currentLoad = w;
            } else {
                currentLoad += w;
            }
        }
        
        return daysNeeded <= daysLimit;
    }
};