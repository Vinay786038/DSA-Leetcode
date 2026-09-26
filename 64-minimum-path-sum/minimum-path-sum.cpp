class Solution {
public:
    int solve(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m||j>=n)
        {
            return INT_MAX;
        }
        if(i==m-1&&j==n-1)
        {
            return grid[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int right=solve(grid,dp,i,j+1);
        int down=solve(grid,dp,i+1,j);
        return dp[i][j]=grid[i][j]+min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(grid,dp,0,0);
        

        
    }
};