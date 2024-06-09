class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_count;
        prefix_count[0] = 1; // To handle cases where the prefix sum itself is divisible by k
        
        int prefix_sum = 0;
        int count = 0;
        
        for (int num : nums) {
            prefix_sum += num;
            int mod = ((prefix_sum % k) + k) % k; // Handling negative remainders
            
            if (prefix_count.find(mod) != prefix_count.end()) {
                count += prefix_count[mod];
            }
            
            prefix_count[mod]++;
        }
        
        return count;
    }
};
