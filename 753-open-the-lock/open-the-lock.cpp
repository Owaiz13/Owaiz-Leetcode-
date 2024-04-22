class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        
        string start = "0000";
        if (dead.count(start)) return -1;
        
        q.push(start);
        visited.insert(start);
        
        int moves = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; ++i) {
                string current = q.front();
                q.pop();
                
                if (current == target) return moves;
                
                for (int j = 0; j < 4; ++j) {
                    for (int d = -1; d <= 1; d += 2) {
                        string next = current;
                        
                        // Turn the wheel
                        next[j] = (next[j] - '0' + d + 10) % 10 + '0';
                        
                        if (!visited.count(next) && !dead.count(next)) {
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }
            
            ++moves;
        }
        
        return -1;
    }
};

