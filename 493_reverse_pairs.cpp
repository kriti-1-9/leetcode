class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        // Count pairs in the left half and right half separately
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

        // Count "cross" pairs: i is in [left, mid], j is in [mid+1, right]
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            // Use 2.0 to avoid integer overflow during the comparison
            while (j <= right && nums[i] > 2.0 * nums[j]) {
                j++;
            }
            // All elements from the original j to the current j satisfy the condition
            count += (j - (mid + 1));
        }

        // Standard merge to keep the array sorted for the next recursive level
        inplace_merge(nums.begin() + left, nums.begin() + mid + 1, nums.begin() + right + 1);
        
        return count;
    }
};