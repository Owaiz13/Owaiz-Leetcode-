class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixXOR(n + 1, 0);
        
        // Compute prefix XOR array
        for (int i = 0; i < n; ++i) {
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        }
        
        int count = 0;
        
        // Iterate through all pairs (i, k)
        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k < n; ++k) {
                if (prefixXOR[i] == prefixXOR[k + 1]) {
                    // If prefixXOR[i] == prefixXOR[k + 1], then for each j such that i < j <= k,
                    // we have a valid triplet (i, j, k).
                    count += (k - i);
                }
            }
        }
        
        return count;
    }
};

