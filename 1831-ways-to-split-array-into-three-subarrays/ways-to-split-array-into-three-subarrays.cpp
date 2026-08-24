class Solution {
public:
    const int MOD=1e9+7;
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
        vector<long long>pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+nums[i];
        }
        long long total=pref[n-1];
        long long ans=0;
        for(int i=0;i<n-2;i++)
        {
            long long left=lower_bound(pref.begin()+i+1,pref.begin()+n-1,2LL*pref[i])-pref.begin();
            long long right=upper_bound(pref.begin()+i+1,pref.begin()+n-1,(total+pref[i])/2)-pref.begin();
            ans+=max(0LL,right-left);
            ans%=MOD;
        }
        return ans;
    }
};