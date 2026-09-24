class Solution {
public:
    int digitsum(int n)
    {
        if(n<=0)
        {
            return 0;
        }
        return n%10+digitsum(n/10);
    }
    int smallestIndex(vector<int>& nums)
    {
        for(int i=0;i<nums.size();i++)
        {
            int ans=digitsum(nums[i]);
            if(ans==i)
            {
                return ans;
            }
        }
        return -1;
        
        
    }
};