class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        int majorCount=nums.size()/2;
        for(int i:nums){
            m[i]++;
        }
        for(auto i:m){
          if(i.second>majorCount){
            return i.first;
          }
        }
        return -1;
       
    }
};