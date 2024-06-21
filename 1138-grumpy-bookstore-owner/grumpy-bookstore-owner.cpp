#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int satisfiedCustomers = 0;
        
        // Calculate the initial satisfied customers without using the secret technique
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                satisfiedCustomers += customers[i];
            }
        }
        
        // Calculate the additional satisfied customers if we use the technique for the first `minutes` interval
        int maxAdditional = 0;
        int currentAdditional = 0;
        
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i] == 1) {
                currentAdditional += customers[i];
            }
        }
        
        maxAdditional = currentAdditional;
        
        // Use sliding window to find the maximum additional customers we can satisfy
        for (int i = minutes; i < n; ++i) {
            if (grumpy[i - minutes] == 1) {
                currentAdditional -= customers[i - minutes];
            }
            if (grumpy[i] == 1) {
                currentAdditional += customers[i];
            }
            maxAdditional = std::max(maxAdditional, currentAdditional);
        }
        
        return satisfiedCustomers + maxAdditional;
    }
};
