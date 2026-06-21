class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>vec;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]==1)
            {
                mp[nums[i]]=0;
            }
            else
            mp[nums[i]]=1;
        }
        for(auto &x:mp)
        {
            if(x.second>0)
            vec.push_back(x.first);
        }
        return vec;
        
    }
};