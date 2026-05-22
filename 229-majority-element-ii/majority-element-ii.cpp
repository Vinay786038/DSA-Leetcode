class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]])
            mp[nums[i]]++;
            else
            mp[nums[i]]=1;
        }
        vector<int>vec;
        for(auto i:mp)
        {
            if(i.second>nums.size()/3)
            vec.push_back(i.first);
        }
        return vec;
        
    }
};