class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int n=nums.size();
        int i=0;
        int j=0;
        for(int k=0;k<n;k++)
        {
            if(nums[k]==1)
            {
                i=k;
                j=k;
                break;
            }
        }
        int ind=-1;
        int ans=0;
        bool x=true;
        while(j<n&&i<n)
        {
            if(nums[i]==0)
            {
                i++;
                continue;
            }
            if(nums[j]==0)
            {
                if(x)
                {
                    x=false;
                    ind=j+1;
                }
                else
                {
                    i=ind;
                    ind=j+1;
                }
            }
            ans=max(ans,j-i);
            j++;
        }
        int zero=0;
        for(int k=i;k<j;k++)
        {
            if(nums[k]==0)
            {
                zero=1;
                break;
            }
        }
        if(zero==0)
        {
            x=true;
        }
        if(x)
        {
            ans=max(ans,j-i);
        }
        if(ans==n)
        return n-1;
        return ans;

        
    }
};