class Solution {
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int ans=0;
        for(auto x:mp)
        {
            if(x.second>1)
            {
                int val=x.second;
                ans+=val*(val-1)/2;
            }
        }
        return ans;
        
    }
};