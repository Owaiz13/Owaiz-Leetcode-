class Solution {
public:
    int heightChecker(vector<int>& heights) {
      vector<int>store=heights;
      int count=0;
      sort(store.begin(),store.end());
      for(int i=0;i<heights.size();i++){
        if (heights[i]!=store[i]){
            count++;
        }
      }
      return count;


    }
};