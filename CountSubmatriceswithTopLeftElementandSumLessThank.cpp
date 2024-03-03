class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> pref(n + 1, vector<int>(m + 1));
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                pref[i][j] = grid[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1]; 
                int cur = pref[i][j] - pref[0][j] - pref[i][0] + pref[0][0];
                if (cur <= k) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
