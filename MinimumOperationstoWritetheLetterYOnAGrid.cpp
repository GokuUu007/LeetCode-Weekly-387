class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        vector<int> count(3), all(3);
        
        for (auto &row : grid) {
            for (auto &ele : row) {
                ++all[ele];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (i < n / 2)
                ++count[grid[i][i]], ++count[grid[i][n - i - 1]];
            else
                ++count[grid[i][n / 2]];
        }
        int tot = accumulate(count.begin(), count.end(), 0);
        int ans = 1e9;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == j) continue;
                int x = tot - count[i];
                int y = n * n - tot - all[j] + count[j];
                ans = min(ans, x + y);
            }
        }
        
        return ans;
    }
};
