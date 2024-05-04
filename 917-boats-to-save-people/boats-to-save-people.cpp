class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end()); // Sort people in ascending order
        int boats = 0;
        int left = 0, right = people.size() - 1;
        
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                // If both people can fit in one boat, move both pointers
                left++;
                right--;
            } else {
                // If not, only the heavier person can fit in one boat, move the right pointer
                right--;
            }
            boats++; // Increment boat count for each encounter
        }
        
        return boats;
    }
};
