class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int balance, vector<vector<char>>& grid)
    {
        // Current cell process
        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        // Invalid
        if (balance < 0)
            return false;

        // Destination
        if (i == m - 1 && j == n - 1)
            return balance == 0;

        // Remaining cells
        int remaining = (m - 1 - i) + (n - 1 - j);

        // Balance ko zero karna possible nahi
        if (balance > remaining)
            return false;

        // Memo
        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool ans = false;

        if (i + 1 < m)
            ans = solve(i + 1, j, balance, grid);

        if (!ans && j + 1 < n)
            ans = solve(i, j + 1, balance, grid);

        return dp[i][j][balance] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid)
    {
        m = grid.size();
        n = grid[0].size();

        // Total path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        // Maximum useful balance = (m+n-1)/2
        int maxBalance = (m + n) / 2 + 1;

        dp.assign(
            m,
            vector<vector<int>>(
                n,
                vector<int>(maxBalance + 1, -1)
            )
        );

        return solve(0, 0, 0, grid);
    }
};