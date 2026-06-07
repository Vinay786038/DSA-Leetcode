class Solution {
public:
    int count(int n)
    {
        int sum=0;
        while(n>0)
        {
            int rem=n%10;
            sum+=rem;
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums)
    {
        map<int,int>mp;
        int res=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            int digit=count(nums[i]);
            if(mp[digit])
            {
                res=max(res,mp[digit]+nums[i]);
                if(mp[digit]<nums[i])
                {
                    mp[digit]=nums[i];
                }
            }
            else
            {
                mp[digit]=nums[i];
            }
        }
        if(res!=INT_MIN)
        return res;
        return -1;
        
        
    }
};