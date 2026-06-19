class Solution {
public:
    void solve(int i,vector<int>&nums,vector<vector<int>>&ans)
    {
        if(i==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int index=i;index<nums.size();index++)
        {
            swap(nums[i],nums[index]);
            solve(i+1,nums,ans);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0,nums,ans);
        return ans;
        
    }
};