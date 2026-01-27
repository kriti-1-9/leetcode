#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return intervals;

        // 1. Sort by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        
        // 2. Start with the first interval
        ans.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            // Get the last interval we added to 'ans'
            // We use a reference (&) so we can modify it directly
            vector<int>& lastInterval = ans.back();

            // If the current interval overlaps with the last one
            if (intervals[i][0] <= lastInterval[1]) {
                // Merge them by updating the end time to the further one
                lastInterval[1] = max(lastInterval[1], intervals[i][1]);
            } 
            else {
                // No overlap, just add it as a new interval
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};