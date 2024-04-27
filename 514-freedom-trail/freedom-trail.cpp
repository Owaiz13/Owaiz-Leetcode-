using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<pair<int, int>, int, pair_hash> memo;
        return dp(ring, key, 0, 0, memo);
    }
    
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const pair<T1, T2>& pair) const {
            auto hash1 = std::hash<T1>{}(pair.first);
            auto hash2 = std::hash<T2>{}(pair.second);
            return hash1 ^ hash2;
        }
    };
    
    int dp(const string& ring, const string& key, int pos, int k, unordered_map<pair<int, int>, int, pair_hash>& memo) {
        if (k == key.length()) {
            return 0;
        }
        if (memo.count({pos, k})) {
            return memo[{pos, k}];
        }
        
        int result = INT_MAX;
        for (int i = 0; i < ring.length(); ++i) {
            if (ring[i] == key[k]) {
                int clockwise_dist = (i - pos + ring.length()) % ring.length();
                int anticlockwise_dist = (pos - i + ring.length()) % ring.length();
                int steps = min(clockwise_dist, anticlockwise_dist) + 1 + dp(ring, key, i, k + 1, memo);
                result = min(result, steps);
            }
        }
        
        memo[{pos, k}] = result;
        return result;
    }
};
