class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // If we are on an upward slope, the peak is to the right
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } 
            // If we are on a downward slope, the peak is at mid or to the left
            else {
                high = mid;
            }
        }
        
        // When low == high, we've found a peak index
        return low;
    }
};