#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfitAssignment(std::vector<int>& difficulty, std::vector<int>& profit, std::vector<int>& worker) {
        // Combine jobs into a vector of pairs (difficulty, profit)
        std::vector<std::pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        
        // Sort jobs by difficulty
        std::sort(jobs.begin(), jobs.end());
        
        // Sort workers by their abilities
        std::sort(worker.begin(), worker.end());
        
        int maxProfit = 0, best = 0, j = 0;
        
        // Iterate through each worker
        for (int i = 0; i < worker.size(); ++i) {
            // Update the best profit we can get for the current worker's ability
            while (j < jobs.size() && jobs[j].first <= worker[i]) {
                best = std::max(best, jobs[j].second);
                ++j;
            }
            // Add the best profit for this worker
            maxProfit += best;
        }
        
        return maxProfit;
    }
};
