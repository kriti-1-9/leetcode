class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return true;

            // Handle the duplicate case where we can't decide the sorted half
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Left side is sorted
            if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1; // Target is in the sorted left half
                } else {
                    low = mid + 1;  // Target is in the right half
                }
            } 
            // Right side is sorted
            else {
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;  // Target is in the sorted right half
                } else {
                    high = mid - 1; // Target is in the left half
                }
            }
        }
        return false;
    }
};