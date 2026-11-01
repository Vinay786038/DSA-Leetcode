class Solution {
public:
    /*bool equal(vector<int>&nums)
    {
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
            {
                return false;
            }
        }
        return true;
    }*/
    int minMoves(vector<int>& nums)
    {
        int n=nums.size();
       /*if(n==2)
        {
            return nums[1]-nums[0];
        }*/
        int min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<min)
            {
                min=nums[i];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=nums[i]-min;
        }
        return ans;
        
    }
};