#include <stack>
#include <string>
#include <algorithm>

class Solution {
public:
    int maximumGain(std::string s, int x, int y) {
        if (x < y) {
            // If y is greater, swap the values and reverse the string to prioritize "ba"
            std::swap(x, y);
            std::reverse(s.begin(), s.end());
        }
        
        int maxPoints = 0;
        
        // First pass: prioritize removing "ab"
        std::stack<char> stack1;
        for (char c : s) {
            if (!stack1.empty() && stack1.top() == 'a' && c == 'b') {
                stack1.pop();
                maxPoints += x;
            } else {
                stack1.push(c);
            }
        }
        
        // Construct the remaining string after first pass
        std::string remaining;
        while (!stack1.empty()) {
            remaining.push_back(stack1.top());
            stack1.pop();
        }
        std::reverse(remaining.begin(), remaining.end());
        
        // Second pass: remove "ba" from the remaining string
        std::stack<char> stack2;
        for (char c : remaining) {
            if (!stack2.empty() && stack2.top() == 'b' && c == 'a') {
                stack2.pop();
                maxPoints += y;
            } else {
                stack2.push(c);
            }
        }
        
        return maxPoints;
    }
};
