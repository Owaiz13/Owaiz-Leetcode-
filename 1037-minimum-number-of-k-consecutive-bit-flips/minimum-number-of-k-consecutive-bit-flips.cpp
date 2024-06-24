class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        ios_base::sync_with_stdio(0); // I/O Speed up
        int flipCount = 0; // Tracks the current number of flips
        int result = 0;    // Tracks the total number of flips performed

        for (int i = 0; i < nums.size(); i++)
        {
            // If the current index is outside the range of the last flip window, adjust flipCount
            if (i >= k && nums[i - k] == -1)
            {
                flipCount--;
            }
            // If the current bit needs to be flipped to become 1
            if (flipCount % 2 == nums[i])
            {
                // If flipping is not possible because the remaining elements are less than k
                if (i + k > nums.size())
                    return -1;
                // Mark the current position as flipped and update counters
                nums[i] = -1;
                // Increase the flip count
                flipCount++;
                // Increase the result
                result++;
            }
        }
        return result;
    }
};