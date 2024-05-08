#include <vector>
#include <string>
#include <map>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        std::vector<std::string> result(score.size());
        std::map<int, int, std::greater<int>> scoreMap;
        
        // Create a map of scores and their indices
        for (int i = 0; i < score.size(); ++i) {
            scoreMap[score[i]] = i;
        }
        
        // Sort the scores in descending order
        std::sort(score.begin(), score.end(), std::greater<int>());
        
        // Assign ranks
        for (int i = 0; i < score.size(); ++i) {
            if (i == 0)
                result[scoreMap[score[i]]] = "Gold Medal";
            else if (i == 1)
                result[scoreMap[score[i]]] = "Silver Medal";
            else if (i == 2)
                result[scoreMap[score[i]]] = "Bronze Medal";
            else
                result[scoreMap[score[i]]] = std::to_string(i + 1);
        }
        
        return result;
    }
};
