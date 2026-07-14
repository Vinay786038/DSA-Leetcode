class Solution {
public:
    static const int MOD=1e9+7;
    int solve(int idx,int g1,int g2,vector<int>&nums,vector<vector<vector<int>>>&dp)
    {
        if(idx==nums.size())
        {
            return (g1>0&&g1==g2)?1:0;
        }
        if(dp[idx][g1][g2]!=-1)
        {
            return dp[idx][g1][g2];
        }
        long long ans=0;
        ans+=solve(idx+1,g1,g2,nums,dp);
        ans+=solve(idx+1,gcd(g1,nums[idx]),g2,nums,dp);
        ans+=solve(idx+1,g1,gcd(g2,nums[idx]),nums,dp);
        return dp[idx][g1][g2]=ans%MOD;
    } 
    int subsequencePairCount(vector<int>& nums)
    {
        int maxx=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            maxx=max(maxx,nums[i]);    
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(maxx+1, vector<int>(maxx+1,-1)));
        return solve(0,0,0,nums,dp);
    }
};