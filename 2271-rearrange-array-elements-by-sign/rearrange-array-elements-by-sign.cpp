class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>ans(n);
        int pi=0;
        int ni=1;
        int i=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                ans[pi]=nums[i];
                pi+=2;
            }
            else
            {
                ans[ni]=nums[i];
                ni+=2;
            }
        } 
        return ans;
    }
};