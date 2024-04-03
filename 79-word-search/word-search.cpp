class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtrack(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
private:
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int wordIndex) {
        if (wordIndex == word.length()) {
            return true;
        }
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[wordIndex]) {
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '#';
        
        bool found = backtrack(board, word, i + 1, j, wordIndex + 1) ||
                     backtrack(board, word, i - 1, j, wordIndex + 1) ||
                     backtrack(board, word, i, j + 1, wordIndex + 1) ||
                     backtrack(board, word, i, j - 1, wordIndex + 1);
        
        board[i][j] = temp;
        
        return found;
    }
};