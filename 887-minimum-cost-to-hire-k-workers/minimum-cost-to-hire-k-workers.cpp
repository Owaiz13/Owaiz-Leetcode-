class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> ratios; // stores wage/quality ratio along with index
        
        // Calculate wage/quality ratio for each worker and store in ratios vector
        for (int i = 0; i < n; ++i) {
            ratios.push_back({(double)wage[i] / quality[i], i});
        }
        
        // Sort workers based on wage/quality ratio
        sort(ratios.begin(), ratios.end());
        
        priority_queue<int> maxHeap; // Max heap to keep track of highest quality
        
        int sumQuality = 0;
        double minCost = numeric_limits<double>::max();
        
        // Iterate through the sorted ratios
        for (auto& ratio : ratios) {
            sumQuality += quality[ratio.second];
            maxHeap.push(quality[ratio.second]);
            
            // If the size of the maxHeap exceeds k, remove the worker with the highest quality
            if (maxHeap.size() > k) {
                sumQuality -= maxHeap.top();
                maxHeap.pop();
            }
            
            // If we have k workers in the group, calculate the total cost
            if (maxHeap.size() == k) {
                minCost = min(minCost, sumQuality * ratio.first);
            }
        }
        
        return minCost;
    }
};