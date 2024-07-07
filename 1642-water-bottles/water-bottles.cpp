class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cola=numBottles;
       
        while(numBottles>=numExchange){
           int newBottles=numBottles/numExchange;
           int remaining=numBottles%numExchange;
           cola+= newBottles;
           numBottles=newBottles+remaining;
        }
        return cola;
    }
};