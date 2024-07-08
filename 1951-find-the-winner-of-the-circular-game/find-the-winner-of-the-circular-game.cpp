class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0;  // Start with the base case for 1 person
        for (int i = 1; i <= n; i++) {
            winner = (winner + k) % i;
        }
        return winner + 1;  // Adjusting to 1-based index
    }
};
