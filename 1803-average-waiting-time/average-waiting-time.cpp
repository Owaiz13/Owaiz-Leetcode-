class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int m=customers.size();
        
        double wait=customers[0][1];
        int time=customers[0][0]+customers[0][1];
        for(int i=1;i<m;i++){
            if(customers[i][0]<time){
                wait+=time+customers[i][1]-customers[i][0];
                time+=customers[i][1];
                }
                else{
                    wait+=customers[i][1];
                    time=customers[i][0]+customers[i][1];
                }
        }
        return wait/m;
    }
};