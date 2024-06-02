class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        // Swap the elements at left and right indices until the pointers meet in the middle
        while (left < right) {
            // Swap elements
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            
            // Move the pointers towards the center
            left++;
            right--;
        }
    }
};
