class Solution {
public:
    int zigZagArrays(int n, int l, int r) 
    {
        int mod=(int)(1e9)+7;
        vector<int>dp(r+1,1);
        for(int i=1;i<n;i++)
        {
            vector<int>next_dp(r+1);
            if(i%2==1)
            { 
                long pre=0;
                for(int x=l;x<=r;x++)
                {
                    next_dp[x]=pre;
                    pre=(pre+dp[x])%mod;
                }
            }
            else
            {
                long suff=0;
                for(int x=r;x>=l;x--)
                {
                    next_dp[x]=suff;
                    suff=(suff+dp[x])%mod;
                }
            }
            dp=next_dp;
        }
        long count=0;
        for(int x=l;x<=r;x++)
        {
            count=(count+dp[x])%mod;
        }
        return (int)((count*2)%mod);
        
    }
};