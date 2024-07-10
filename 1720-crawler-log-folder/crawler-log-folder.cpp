class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int>s;
        for(auto i:logs){
            if(i=="../"){
                if(s.empty())continue;
                s.pop();
                
            }
            else if(i=="./")continue;
            
            else{
                s.push(1);
            }
        }
        return s.size();
    }
};