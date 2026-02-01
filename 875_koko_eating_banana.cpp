class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canFinish(piles, h, mid)) {
                ans = mid;      // This speed works, but can we go slower?
                high = mid - 1;
            } else {
                low = mid + 1;  // Too slow, need to speed up
            }
        }
        return ans;
    }
    
private:
    bool canFinish(vector<int>& piles, int h, int speed) {
        long long hoursSpent = 0;
        for (int pile : piles) {
            // Calculate ceiling of pile/speed
            hoursSpent += (pile + speed - 1) / speed;
            if (hoursSpent > h) return false; // Optimization: exit early
        }
        return hoursSpent <= h;
    }
};