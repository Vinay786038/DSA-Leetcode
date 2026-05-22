class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int,int>> ans;
        int max=0;
        vector<int>vec;
        for(auto i:mp)
        {
            ans.push_back({i.second,i.first});
        }
        sort(ans.begin(),ans.end(),greater<pair<int,int>>());
        for(int i=0;i<k;i++)
        {
            vec.push_back(ans[i].second);
        }

        return vec;
    }
};