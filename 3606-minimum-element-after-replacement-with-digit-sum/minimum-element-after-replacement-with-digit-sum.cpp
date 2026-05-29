class Solution {
public:
    int minElement(vector<int>& nums)
    {
        int res=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            int sum=0;
            while(x>0)
            {
                int rem=x%10;
                sum+=rem;
                x/=10;
            }
            res=min(res,sum);
        }
        return res;
        
    }
};