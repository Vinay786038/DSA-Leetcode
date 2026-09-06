class Solution {
public:
    int solve(vector<vector<int>>&dp,string s,string t,int i,int j)
    {
        if(j==0)
        {
            return dp[i][j]=1;
        }
        if(i==0)
        {
            return dp[i][j]=0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i-1]==t[j-1])
        {
            return dp[i][j]=solve(dp,s,t,i-1,j-1)+solve(dp,s,t,i-1,j);
        }
        return dp[i][j]=solve(dp,s,t,i-1,j);
        
    }
    int numDistinct(string s, string t)
    {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        return solve(dp,s,t,s.size(),t.size());

        
    }
};