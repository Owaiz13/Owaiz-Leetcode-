class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double low = 0.0, high = 1.0;
        vector<int> result(2);

        while (low < high) {
            double mid = low + (high - low) / 2;
            int count = 0;
            pair<int, int> maxFraction = {0, 1}; // Store the maximum fraction with denominator less than mid
            
            for (int i = 0, j = 0; i < n; ++i) {
                while (j < n && arr[i] >= arr[j] * mid) ++j;
                count += n - j;
                if (j < n && maxFraction.first * arr[j] < maxFraction.second * arr[i]) {
                    maxFraction = {arr[i], arr[j]};
                }
            }

            if (count == k) {
                result[0] = maxFraction.first;
                result[1] = maxFraction.second;
                return result;
            } else if (count < k) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return result;
    }
};