class Solution {
public:
    bool isMonotonic(vector<int>& nums)
    {
        bool x=true;
        bool y=true;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i])
            x=false;
        }
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i])
            y=false;
        }
        return (x||y);
    }
};