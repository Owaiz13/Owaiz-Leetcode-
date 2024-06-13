class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int sum=0;
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int i=0;
        int j=0;
        // while(i<students.size()){
        //     sum=sum+abs(students[i]-seats[i]);
        //     i++;


        // }
        for(int i=0;i<students.size();i++){
            sum=sum+abs(students[i]-seats[i]);
        }
        return sum;
    }
};