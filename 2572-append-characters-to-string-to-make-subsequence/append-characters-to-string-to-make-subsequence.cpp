class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0; // pointer for s
        int j = 0; // pointer for t
        
        // Traverse through s
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                j++; // move to the next character in t
            }
            i++; // move to the next character in s
        }
        
        // The number of characters to append is the remaining characters in t
        return t.size() - j;
    }
};
