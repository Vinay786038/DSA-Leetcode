class Solution {
public:
    int minMoves(vector<int>& nums)
    {
        int n=nums.size();
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            maxx=max(nums[i],maxx);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=maxx-nums[i];
        }
        return ans;

        
    }
};