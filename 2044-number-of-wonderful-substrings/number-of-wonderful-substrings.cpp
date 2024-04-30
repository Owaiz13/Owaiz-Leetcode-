class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> count(1024, 0); // Stores counts of substrings with each bitmask
        count[0] = 1; // Empty string is wonderful
        int bitmask = 0;
        long long result = 0;

        for (char c : word) {
            bitmask ^= 1 << (c - 'a'); // Flip the bit corresponding to the current character
            
            // Count substrings with the current bitmask and all its variations
            result += count[bitmask]; // Substrings with exactly one odd count
            for (int i = 0; i < 10; ++i) {
                result += count[bitmask ^ (1 << i)]; // Substrings with exactly one odd count after toggling one bit
            }

            ++count[bitmask]; // Increment count for the current bitmask
        }

        return result;
    }
};