#include <vector>
#include <algorithm>

class Solution {
public:
    long long maximumImportance(int n, std::vector<std::vector<int>>& roads) {
        // Step 1: Count the degree of each city
        std::vector<int> degree(n, 0);
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        
        // Step 2: Create a vector of pairs (degree, city index)
        std::vector<std::pair<int, int>> degree_city;
        for (int i = 0; i < n; ++i) {
            degree_city.push_back({degree[i], i});
        }
        
        // Step 3: Sort the cities by their degree in descending order
        std::sort(degree_city.rbegin(), degree_city.rend());
        
        // Step 4: Assign values from n to 1 to the cities based on their degrees
        std::vector<int> value(n, 0);
        int current_value = n;
        for (const auto& pair : degree_city) {
            value[pair.second] = current_value--;
        }
        
        // Step 5: Calculate the total importance of all roads
        long long total_importance = 0;
        for (const auto& road : roads) {
            total_importance += value[road[0]] + value[road[1]];
        }
        
        return total_importance;
    }
};
