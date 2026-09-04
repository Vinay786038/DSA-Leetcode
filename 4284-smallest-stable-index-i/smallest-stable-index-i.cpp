class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k)
    {
        int n=nums.size();
        int ans=INT_MAX;
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            maxx=max(maxx,nums[i]);
            int minn=INT_MAX;
            for(int j=i;j<n;j++)
            {
                minn=min(minn,nums[j]);
            }
            if(maxx-minn<=k)
            {
                ans=min(ans,i);
            }
        }
        if(ans==INT_MAX)
        return -1;
        return ans;
        
    }
};