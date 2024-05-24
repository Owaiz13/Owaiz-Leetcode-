class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        // Helper function for backtracking
        function<void(int, unordered_map<int, int>&)> backtrack = [&](int start, unordered_map<int, int>& freqMap) {
            // Base case: for every call to this function after initial call, it counts as a valid subset
            if (start > 0) {
                count++;
            }
            
            // Try to include each number in the subset
            for (int i = start; i < n; ++i) {
                int num = nums[i];
                
                // Check if adding this number would violate the condition
                if (freqMap[num - k] == 0 && freqMap[num + k] == 0) {
                    freqMap[num]++;
                    backtrack(i + 1, freqMap); // Recur with the next index
                    freqMap[num]--; // Backtrack step
                }
            }
        };

        // Initialize frequency map
        unordered_map<int, int> freqMap;
        // Start backtracking from index 0
        backtrack(0, freqMap);
        
        return count;
    }
};
