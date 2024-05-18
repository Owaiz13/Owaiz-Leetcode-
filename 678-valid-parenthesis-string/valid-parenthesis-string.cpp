class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;  // Minimum number of unmatched '('
        int high = 0; // Maximum number of unmatched '('

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else if (c == '*') {
                low--;  // Treat '*' as ')'
                high++; // Treat '*' as '('
            }

            if (high < 0) {
                return false; // Too many ')'
            }

            if (low < 0) {
                low = 0; // Reset low to zero, because we can't have negative unmatched '('
            }
        }

        return low == 0;
    }
};
