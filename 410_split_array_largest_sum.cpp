class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long low = 0, high = 0;
        for (int n : nums) {
            low = max(low, (long long)n); // Max element
            high += n;                   // Total sum
        }
        
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1; // Try to minimize the largest sum further
            } else {
                low = mid + 1;  // Limit is too small, increase it
            }
        }
        return (int)ans;
    }

private:
    bool canSplit(vector<int>& nums, int k, long long limit) {
        int subarrays = 1;
        long long currentSum = 0;
        
        for (int n : nums) {
            if (currentSum + n > limit) {
                subarrays++;
                currentSum = n;
                if (subarrays > k) return false;
            } else {
                currentSum += n;
            }
        }
        return true;
    }
};