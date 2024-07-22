class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        vector<int>min;
        
        vector<int>max;
        for(int i=0;i<matrix.size();i++){
            int mini=INT_MAX;
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]<mini){
                    mini=matrix[i][j];
                }

            }
            min.push_back(mini);
        }
        for(int i=0;i<matrix[0].size();i++){
            int maxi=INT_MIN;
            for(int j=0;j<matrix.size();j++){
                if(matrix[j][i]>maxi){
                    maxi=matrix[j][i];
                }

            }
            max.push_back(maxi);
        }
        vector<int>ans;
        for(int i=0;i<min.size();i++){
            for(int j=0;j<max.size();j++){
                if(min[i]==max[j]){
                    ans.push_back(min[i]);
                }
            }
        }
        return ans;

    }
};