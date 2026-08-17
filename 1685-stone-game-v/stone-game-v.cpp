class Solution
{
public:

    vector<int> prefix;
    vector<vector<int>> dp;

    int solve(vector<int>& stoneValue, int l, int r)
    {
        if (l == r)
        {
            return 0;
        }

        if (dp[l][r] != -1)
        {
            return dp[l][r];
        }

        int best = 0;

        for (int k = l; k < r; k++)
        {
            int leftSum = prefix[k + 1] - prefix[l];

            int rightSum = prefix[r + 1] - prefix[k + 1];

            if (leftSum < rightSum)
            {
                best = max(best,
                           leftSum + solve(stoneValue, l, k));
            }
            else if (leftSum > rightSum)
            {
                best = max(best,
                           rightSum + solve(stoneValue, k + 1, r));
            }
            else
            {
                best = max(best,
                           leftSum +
                           max(solve(stoneValue, l, k),
                               solve(stoneValue, k + 1, r)));
            }
        }

        return dp[l][r] = best;
    }

    int stoneGameV(vector<int>& stoneValue)
    {
        int n = stoneValue.size();

        prefix.resize(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        dp.assign(n, vector<int>(n, -1));

        return solve(stoneValue, 0, n - 1);
    }
};