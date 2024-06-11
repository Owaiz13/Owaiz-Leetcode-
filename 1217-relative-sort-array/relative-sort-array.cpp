class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        // Create a map to store the indices of elements in arr2
        std::unordered_map<int, int> indexMap;
        for (int i = 0; i < arr2.size(); ++i) {
            indexMap[arr2[i]] = i;
        }
        
        // Custom comparator function to sort arr1
        auto customSort = [&](int a, int b) {
            // If both elements are present in arr2, sort them based on their indices in arr2
            if (indexMap.find(a) != indexMap.end() && indexMap.find(b) != indexMap.end()) {
                return indexMap[a] < indexMap[b];
            }
            // If only one element is present in arr2, prioritize it
            else if (indexMap.find(a) != indexMap.end()) {
                return true;
            }
            else if (indexMap.find(b) != indexMap.end()) {
                return false;
            }
            // If neither element is present in arr2, sort them in ascending order
            else {
                return a < b;
            }
        };
        
        // Sort arr1 using the custom comparator
        std::sort(arr1.begin(), arr1.end(), customSort);
        
        return arr1;
    }
};