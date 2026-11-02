class Solution {
public:
    int minMoves2(vector<int>& nums)
    {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        int i=0;
        n--;
        while(i<n)
        {
            ans+=nums[n]-nums[i];
            i++;
            n--;
        }
        return ans;

        
    }
};