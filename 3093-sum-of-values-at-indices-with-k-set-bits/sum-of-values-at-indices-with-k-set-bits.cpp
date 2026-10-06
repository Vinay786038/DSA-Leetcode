class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k)
    {
        vector<int>ans(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++)
        {
            ans[i]=ans[i>>1]+(i&1);
        }
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(ans[i]==k)
            {
                res+=nums[i];
            }
        }
        return res;
    }
};