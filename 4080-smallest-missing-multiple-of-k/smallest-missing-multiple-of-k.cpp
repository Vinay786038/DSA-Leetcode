class Solution {
public:
    int missingMultiple(vector<int>& nums, int k)
    {
        unordered_map<int,bool>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=true;
        }
        int x=1;
        k=k*x;
        int m=k;
        while(mp[m]==true)
        {
            x++;
            m=k*x;
        }
        return m;
        
    }
};