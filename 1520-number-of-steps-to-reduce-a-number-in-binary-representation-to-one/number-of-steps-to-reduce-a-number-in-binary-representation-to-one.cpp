class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        // Start from the least significant bit (rightmost bit)
        for (int i = s.size() - 1; i > 0; --i) {
            if (s[i] - '0' + carry == 1) {
                // If the bit is 1 (with carry), make it 0 and set carry for next bit
                steps += 2; // 1 step for adding 1 and another step for the subsequent division by 2
                carry = 1;
            } else {
                // If the bit is 0 (with carry 0) or 1 (with carry 1 which results in 0)
                steps += 1; // Just divide by 2
            }
        }
        // Finally handle the leftmost bit
        steps += carry;
        return steps;
    }
};
