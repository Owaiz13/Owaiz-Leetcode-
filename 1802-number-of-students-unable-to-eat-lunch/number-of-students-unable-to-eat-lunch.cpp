class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int unable_to_eat = 0;
        
        // Iterate through the students queue
        while (!students.empty()) {
            // Check if the student at the front prefers the sandwich at the top of the stack
            if (students[0] == sandwiches[0]) {
                // If yes, remove that student and the top sandwich
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                unable_to_eat = 0;  // Reset the count of unable to eat students
            } else {
                // If no, move that student to the end of the queue
                students.push_back(students[0]);
                students.erase(students.begin());
                unable_to_eat++;
            }
            
            // If all students are unable to eat, break the loop
            if (unable_to_eat == students.size()) {
                break;
            }
        }
        
        return unable_to_eat;
    }
};
