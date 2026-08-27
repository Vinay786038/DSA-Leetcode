class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<int>ans;
        int len=1;
        for(int i=0;i<n;i++)
        {
            if(i>0&&nums[i]==nums[i-1]+1)
            {
                len++;
            }
            else
            {
                len=1;
            }
            if(len>=k)
            {
                ans.push_back(nums[i]);
            }
            else if(i>=k-1)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};