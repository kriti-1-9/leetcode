class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (calculateSum(nums, mid) <= threshold) {
                ans = mid;      // This works, but can we find a smaller one?
                high = mid - 1;
            } else {
                low = mid + 1;  // Sum is too high, we need a larger divisor
            }
        }
        return ans;
    }

private:
    long long calculateSum(vector<int>& nums, int divisor) {
        long long total = 0;
        for (int n : nums) {
            // Ceiling division trick: (a + b - 1) / b
            total += (n + divisor - 1) / divisor;
        }
        return total;
    }
};