class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int totalSubsets = 1 << n; // 2^n subsets
        vector<vector<int>> result;
        
        for (int subsetMask = 0; subsetMask < totalSubsets; ++subsetMask) {
            vector<int> subset;
            for (int i = 0; i < n; ++i) {
                // Check if the ith element is included in the subset
                if (subsetMask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            result.push_back(subset);
        }
        
        return result;
    }
};
