class Solution {
public:
    int maxSum(vector<int>& nums, int k)
    {
        long long MOD=1e9+7;
        vector<int>cnt(32,0);
        for(int x:nums)
        {
            for(int bit=0;bit<31;bit++)
            {
                if(x&(1<<bit))
                {
                    cnt[bit]++;
                }
            }
        }
        long long ans=0;
        for(int i=0;i<k;i++)
        {
            long long x=0;
            for(int bit=30;bit>=0;bit--)
            {
                if(cnt[bit]>0)
                {
                    x|=(1LL<<bit);
                    cnt[bit]--;
                }
            }
            ans=(ans+x*x)%MOD;
        }
        return ans;
    }
};