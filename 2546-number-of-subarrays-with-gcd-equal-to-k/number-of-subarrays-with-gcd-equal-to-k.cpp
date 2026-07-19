class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k)
    {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x=gcd(nums[i],nums[i]);
            for(int j=i;j<n;j++)
            {
                x=gcd(x,nums[j]);
                if(x==k)
                ans++;
            }
        }
        return ans;       
    }
};