class Solution {
public:
    int abs(int a,int b)
    {
        if(a>b)
        return a-b;
        return b-a;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                if(i-mp[nums[i]]<=k)
                return true;
            }
            mp[nums[i]]=i;
        }
        return false;
        
        
    }
};