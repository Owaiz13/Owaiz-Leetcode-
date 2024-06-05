#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
        // Initialize a vector to store the minimum frequency of each character
        std::vector<int> minFreq(26, INT_MAX);

        // Update minFreq for each word
        for (const std::string& word : words) {
            // Temporary frequency vector for the current word
            std::vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            // Update the minimum frequency
            for (int i = 0; i < 26; ++i) {
                minFreq[i] = std::min(minFreq[i], freq[i]);
            }
        }

        // Construct the result based on the minimum frequencies
        std::vector<std::string> result;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < minFreq[i]; ++j) {
                result.push_back(std::string(1, i + 'a'));
            }
        }

        return result;
    }
};
