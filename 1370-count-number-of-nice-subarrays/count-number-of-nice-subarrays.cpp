#include <vector>
#include <unordered_map>

class Solution {
public:
    int numberOfSubarrays(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // There is one way to have 0 odd numbers initially.
        
        int currentPrefixSum = 0;
        int countNiceSubarrays = 0;
        
        for (int num : nums) {
            // Update currentPrefixSum to count the number of odd numbers
            if (num % 2 == 1) {
                currentPrefixSum++;
            }
            
            // Check if there exists a subarray ending at the current index with exactly k odd numbers
            if (prefixCount.find(currentPrefixSum - k) != prefixCount.end()) {
                countNiceSubarrays += prefixCount[currentPrefixSum - k];
            }
            
            // Increment the count of currentPrefixSum in the hash map
            prefixCount[currentPrefixSum]++;
        }
        
        return countNiceSubarrays;
    }
};
