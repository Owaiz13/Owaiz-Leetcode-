class Solution {
public:
    string reverseParentheses(string s) {
         std::stack<char> stk;

        for (char ch : s) {
            if (ch == ')') {
                std::string temp;
                while (!stk.empty() && stk.top() != '(') {
                    temp += stk.top();
                    stk.pop();
                }
                if (!stk.empty()) {
                    stk.pop();  // remove the '('
                }
                for (char temp_ch : temp) {
                    stk.push(temp_ch);
                }
            } else {
                stk.push(ch);
            }
        }

        std::string result;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};