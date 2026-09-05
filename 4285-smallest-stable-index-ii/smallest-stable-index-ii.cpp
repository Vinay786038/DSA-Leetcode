class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<int>pref(n);
        vector<int>suff(n);
        int maxx=INT_MIN;
        int minn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            maxx=max(maxx,nums[i]);
            pref[i]=maxx;
            minn=min(minn,nums[n-1-i]);
            suff[n-i-1]=minn;
        }
        for(int i=0;i<n;i++)
        {
            if(pref[i]-suff[i]<=k)
            {
                return i;
            }
        }
        return -1;

        
    }
};