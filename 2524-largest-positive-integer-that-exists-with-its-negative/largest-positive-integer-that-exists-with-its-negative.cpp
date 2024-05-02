class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int maxK = -1;
        
        for (int num : nums) {
            if (numSet.find(-num) != numSet.end()) {
                maxK = std::max(maxK, std::abs(num));
            }
        }
        
        return maxK != -1 ? maxK : -1;
    }
};