#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderIndexMap;
        remainderIndexMap[0] = -1;  // Initialize to handle cases where subarray starts from index 0
        int prefixSum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            int remainder = prefixSum % k;
            if (remainder < 0) remainder += k;  // Handle negative remainders
            
            if (remainderIndexMap.find(remainder) != remainderIndexMap.end()) {
                if (i - remainderIndexMap[remainder] > 1) {
                    return true;
                }
            } else {
                remainderIndexMap[remainder] = i;
            }
        }
        
        return false;
    }
};
