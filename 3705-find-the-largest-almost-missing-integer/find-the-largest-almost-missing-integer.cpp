class Solution {
public:
    int largestInteger(vector<int>& nums, int k)
    {
        unordered_map<int,int>mp;
        int maxx=0;
        for(int i=0;i<nums.size();i++)
        {
            maxx=max(maxx,nums[i]);
            mp[nums[i]]++;
        }
        if(k==nums.size())
        {
            return maxx;
        }
        int first=nums[0];
        int last=nums[nums.size()-1];
        if(k==1)
        {
            maxx=-1;
            for(auto x:mp)
            {
                if(x.second==1)
                {
                    maxx=max(maxx,x.first);
                }
            }
            return maxx;
        }
        if(mp[last]==1&&mp[first]==1)
        {
            return max(first,last);
        }
        if(mp[first]==1)
        {
            return first;
        }
        if(mp[last]==1)
        {
            return last;
        }
        return -1;
    }
};