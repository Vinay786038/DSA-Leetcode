class Solution {
public:
    int longestSubsequence(vector<int>& nums)
    {
        int n=nums.size();
        int xr=0;
        int zero=0;
        for(int i=0;i<n;i++)
        {
            xr^=nums[i];
            if(nums[i]==0)
            {
                zero++;
            }
            
        }
        if(xr!=0)
        return n;
        if(zero==n)
        {
            return 0;
        }
        return n-1;
        
    }
};