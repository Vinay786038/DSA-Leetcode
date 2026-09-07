class Solution {
public:
    const int MOD=1e9+7;
    int distinctSubseqII(string s) 
    {
        vector<long long>dp(26,0);
        long long total=0;
        for(char c:s)
        {
            int x=c-'a';
            long long newvalue=(total+1)%MOD;
            total=(total-dp[x]+MOD)%MOD;
            dp[x]=newvalue;
            total=(total+dp[x])%MOD;
        }
        return total;

        
    }
};