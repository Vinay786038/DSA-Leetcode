class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int n=nums.size();
        if(n<3)
        return 0;
        int ans=0;
        int curr=2;
        for(int i=2;i<n;i++)
        {
            if(nums[i]==nums[i-1]+nums[i-2])
            {
                curr++;
                ans=max(ans,curr);
            }
            else
            {
                ans=max(ans,curr);
                curr=2;
            }

        }
        return ans>=2?ans:0;


        
    }
};