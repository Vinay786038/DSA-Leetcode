class Solution {
public:
    int find(int i,int j,vector<int>&piles,vector<vector<int>>&dp)
    {
        if(i==j)
        {
            return piles[i];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int leftmax=piles[i]-find(i+1,j,piles,dp);
        int rightmax=piles[j]-find(i,j-1,piles,dp);
        return dp[i][j]=max(leftmax,rightmax);
    }
    bool stoneGame(vector<int>& piles)
    {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return find(0,n-1,piles,dp)>0;
    }
};