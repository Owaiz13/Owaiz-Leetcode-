class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentPartition;
        backtrack(s, 0, currentPartition, result);
        return result;
    }
    
private:
    void backtrack(const string& s, int start, vector<string>& currentPartition, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(currentPartition);
            return;
        }
        
        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                currentPartition.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, currentPartition, result);
                currentPartition.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
