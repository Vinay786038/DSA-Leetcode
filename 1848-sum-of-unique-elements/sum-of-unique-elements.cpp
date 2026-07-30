class Solution {
public:
    int sumOfUnique(vector<int>& nums)
    {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                mp[nums[i]]++;
            }
            else
            {
                mp[nums[i]]=1;
            }
        }
        int ans=0;
        for(auto x:mp)
        {
            if(x.second==1)
            {
                ans+=x.first;
            }
        }
        return ans;

        
    }
};