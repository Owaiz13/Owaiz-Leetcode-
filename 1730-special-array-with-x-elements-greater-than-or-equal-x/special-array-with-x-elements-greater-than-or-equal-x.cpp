class Solution {
public:
    int specialArray(vector<int>& nums) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Iterate through possible values of x
        int n = nums.size();
        for (int x = 0; x <= n; ++x) {
            // Find how many numbers are greater than or equal to x
            int count = countGreaterOrEqual(nums, x);
            
            // If exactly x numbers are greater than or equal to x, return x
            if (count == x) {
                return x;
            }
        }
        
        // If no such x is found, return -1
        return -1;
    }
    
private:
    // Helper function to count how many numbers in nums are greater than or equal to x
    int countGreaterOrEqual(const vector<int>& nums, int x) {
        int n = nums.size();
        int left = 0, right = n;
        
        // Binary search for the first index where nums[index] >= x
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        // All elements from `left` to `n-1` are >= x
        return n - left;
    }
};
