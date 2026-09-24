class Solution {
public:
    int smallestIndex(vector<int>& nums)
    {
        for(int i=0;i<nums.size();i++)
        {
            int ans=0;
            int n=nums[i];
            while(n>0)
            {
                ans+=n%10;
                n/=10;
            }
            if(ans==i)
            {
                return ans;
            }
        }
        return -1;
        
        
    }
};