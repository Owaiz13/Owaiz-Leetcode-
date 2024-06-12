class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int mid=0;
        int low=0;
        int high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                std ::swap(nums[low],nums[mid]);
                
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                
                mid++;

            }
            else{
               std ::swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};