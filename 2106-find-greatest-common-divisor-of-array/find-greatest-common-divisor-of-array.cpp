class Solution {
public:
    int findGCD(vector<int>& nums)
    {
        int mini=nums[0];
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<mini)
            {
                mini=nums[i];
            }
            if(nums[i]>maxi)
            {
                maxi=nums[i];
            }
        }
        for(int i=mini;i>1;i--)
        {
            if(maxi%i==0&&mini%i==0)
            return i;
        }
        return 1;
        
    }
};