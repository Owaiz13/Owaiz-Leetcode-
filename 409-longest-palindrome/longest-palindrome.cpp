#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> charCount;
        
        // Count the occurrences of each character
        for (char c : s) {
            charCount[c]++;
        }
        
        int length = 0;
        bool oddCountFound = false;
        
        // Calculate the length of the longest palindrome
        for (auto& entry : charCount) {
            if (entry.second % 2 == 0) {
                length += entry.second;  // Use all even counts
            } else {
                length += entry.second - 1;  // Use the largest even count less than the odd count
                oddCountFound = true;
            }
        }
        
        // Add one more character in the center if there is any odd count
        if (oddCountFound) {
            length++;
        }
        
        return length;
    }
};
