class Solution {
public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        int n = profits.size();
        std::vector<std::pair<int, int>> projects(n);
        
        for (int i = 0; i < n; ++i) {
            projects[i] = {capital[i], profits[i]};
        }
        
        // Sort projects based on the required capital
        std::sort(projects.begin(), projects.end());
        
        // Max-heap to keep track of maximum profits we can start
        std::priority_queue<int> maxHeap;
        
        int currentCapital = w;
        int projectIndex = 0;
        
        for (int i = 0; i < k; ++i) {
            // Push all the projects we can afford with current capital into the max-heap
            while (projectIndex < n && projects[projectIndex].first <= currentCapital) {
                maxHeap.push(projects[projectIndex].second);
                ++projectIndex;
            }
            
            // If we cannot start any project, break the loop
            if (maxHeap.empty()) {
                break;
            }
            
            // Add the profit of the project with the highest profit we can afford
            currentCapital += maxHeap.top();
            maxHeap.pop();
        }
        
        return currentCapital;
    }
};