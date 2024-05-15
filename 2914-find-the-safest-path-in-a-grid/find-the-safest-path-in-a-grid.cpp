class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Step 1: Calculate the minimum distance from each cell to the nearest thief using multi-source BFS
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        // Initialize the queue with all thief positions
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    distance[r][c] = 0;
                }
            }
        }
        
        vector<int> dirs = {-1, 0, 1, 0, -1};  // 4 directions for BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i];
                int nc = c + dirs[i+1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && distance[nr][nc] == INT_MAX) {
                    distance[nr][nc] = distance[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        // Step 2: Binary search for the maximum safeness factor
        auto canReach = [&](int safeness) {
            if (distance[0][0] < safeness) return false;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            queue<pair<int, int>> q;
            q.push({0, 0});
            visited[0][0] = true;
            
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                if (r == n-1 && c == n-1) return true;
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dirs[i];
                    int nc = c + dirs[i+1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && distance[nr][nc] >= safeness) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            
            return false;
        };
        
        int left = 0, right = n + n - 2, best = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canReach(mid)) {
                best = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return best;
    }
};