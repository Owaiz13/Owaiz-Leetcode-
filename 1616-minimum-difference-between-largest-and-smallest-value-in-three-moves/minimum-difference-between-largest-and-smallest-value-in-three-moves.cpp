class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<5){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int min_diff=INT_MAX;
        min_diff=min(min_diff,nums[n-1]-nums[3]);
        min_diff=min(min_diff,nums[n-4]-nums[0]);
        min_diff=min(min_diff,nums[n-2]-nums[2]);
        min_diff=min(min_diff,nums[n-3]-nums[1]);
        return min_diff;

    
    }
};