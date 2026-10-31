class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[501][501][2];

    int paths(vector<vector<int>>& grid, int i, int j,
              bool right, bool down)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || j >= n)
            return 0;

        if (i == m-1 && j == n-1)
            return 1;

        // right = previous movement Right
        // down = previous movement Down

        int dir = right ? 0 : 1;

        if (dp[i][j][dir] != -1)
            return dp[i][j][dir];

        long long ans = 0;

        if (grid[i][j] == 0)
        {
            // Move Down
            ans += paths(grid, i+1, j, false, true);

            // Move Right
            ans += paths(grid, i, j+1, true, false);
        }
        else
        {
            // Entered mirror while moving Right
            if (right)
                ans += paths(grid, i+1, j, false, true);

            // Entered mirror while moving Down
            if (down)
                ans += paths(grid, i, j+1, true, false);
        }

        return dp[i][j][dir] = ans % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid)
    {
        memset(dp, -1, sizeof(dp));

        return paths(grid, 0, 0, false, false);
    }
};