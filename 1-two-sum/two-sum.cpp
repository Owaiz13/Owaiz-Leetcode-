class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create an unordered_map to store the elements and their indices
        unordered_map<int, int> num_map;
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); ++i) {
            // Calculate the complement (target - num)
            int complement = target - nums[i];
            
            // Check if the complement exists in the map
            if (num_map.find(complement) != num_map.end()) {
                // Return the indices of the current number and its complement
                return {num_map[complement], i};
            }
            
            // Store the current number and its index in the map
            num_map[nums[i]] = i;
        }
        
        // If no solution is found, return an empty vector or handle it as per your requirement
        return {};
    }
};