class Solution {
public:
    int passThePillow(int n, int time) {
        int t=time;
        int num=n-1;
        if((t/num)%2==1){
            return n-t%num;
        }
        else{
            return t%num+1;
        }
        
    }
};