class Solution {
public:
    std::string makeGood(std::string s) {
        std::stack<char> stack;
        
        for (char ch : s) {
            if (!stack.empty() && std::abs(stack.top() - ch) == 32) {
                stack.pop();
            } else {
                stack.push(ch);
            }
        }
        
        std::string result;
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        
        return result;
    }
};
