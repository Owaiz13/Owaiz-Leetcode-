class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        int n = nums.size();
        int xorSum = 0;
        for (int num : nums)
            xorSum ^= num;
        
        int targetXOR = xorSum ^ k;
        std::bitset<32> bits(targetXOR);
        return bits.count();
    }
};