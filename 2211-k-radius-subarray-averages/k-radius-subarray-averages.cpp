class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<int>ans(n,-1);
        if(k>n)
        {
            return ans;
        }
        if(k==0)
        {
            return nums;
        }
        vector<long long>pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+nums[i];
        }
        int val=2*k+1;
        for(int i=k;i<n-k;i++)
        {
            long long sum=pref[i+k]-pref[i-k]+nums[i-k];
            ans[i]=sum/val;
        }
        return ans;
        
    }
};