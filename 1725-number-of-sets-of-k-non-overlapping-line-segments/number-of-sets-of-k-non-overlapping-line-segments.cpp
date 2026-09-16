class Solution {
public:
    const long long MOD=1e9+7;
    int numberOfSets(int n, int k)
    {
        long long ans=1;
        for(int i=1;i<=2*k;i++)
        {
            ans=ans*(n+k-i)%MOD;
            long long x=i;
            long long p=MOD-2;
            long long inv=1;
            while(p)
            {
                if(p&1)
                inv=inv*x%MOD;
                x=x*x%MOD;
                p>>=1;
                
            }
            ans=ans*inv%MOD;
        }
        return ans;
    }
};