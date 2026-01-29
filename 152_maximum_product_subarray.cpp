class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Initialize with the first element
        int res = nums[0];
        int curMax = nums[0];
        int curMin = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int n = nums[i];

            // If n is negative, the max becomes the min and min becomes max
            if (n < 0) {
                swap(curMax, curMin);
            }

            // At each step, the new max/min is either the number itself
            // or the number multiplied by the previous max/min
            curMax = max(n, curMax * n);
            curMin = min(n, curMin * n);

            // Update the global result
            res = max(res, curMax);
        }

        return res;
    }
};