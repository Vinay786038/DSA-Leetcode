class Solution {
public:
    bool isMonotonic(vector<int>& nums)
    {
        int n=nums.size();
        if(n==1||n==2)
        return true;
        int x=0;
        int y=0;
        if(nums[0]<=nums[1])
        x++;
        if(nums[0]>=nums[1])
        y++;
        
        
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                x++;
            }
            else
            {
                if(nums[i]==nums[i+1])
                {
                    x++;
                    y++;
                }
                else
                y++;
            }
        }
        if(x==n||y==n)
        return true;
        return false;
    }
};