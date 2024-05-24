class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        // Step 1: Create a frequency count of available letters
        vector<int> letterCount(26, 0);
        for (char ch : letters) {
            letterCount[ch - 'a']++;
        }
        
        // Step 2: Calculate the score for each word
        int n = words.size();
        vector<int> wordScores(n, 0);
        for (int i = 0; i < n; ++i) {
            for (char ch : words[i]) {
                wordScores[i] += score[ch - 'a'];
            }
        }
        
        int maxScore = 0;
        
        // Step 3: Generate all subsets of words using bit manipulation
        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> currentCount(26, 0);
            int currentScore = 0;
            bool valid = true;
            
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    // Step 4: Check if the current subset is valid
                    for (char ch : words[i]) {
                        currentCount[ch - 'a']++;
                        if (currentCount[ch - 'a'] > letterCount[ch - 'a']) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        currentScore += wordScores[i];
                    } else {
                        break;
                    }
                }
            }
            
            if (valid) {
                maxScore = max(maxScore, currentScore);
            }
        }
        
        return maxScore;
    }
};
