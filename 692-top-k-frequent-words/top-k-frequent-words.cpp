class Solution {
public:
    static bool sortByValue(const pair<string,int>&a,const pair<string,int>&b)
    {
        if(a.second!=b.second)
        {
            return a.second>b.second;
        }
        return a.first<b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        map<string,int>mp;
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        vector<pair<string,int>>vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),sortByValue);
        vector<string>ans;
        int x=k;
        for(int i=0;i<k;i++)
        {
            ans.push_back(vec[i].first);
        }
        return ans;
        
    }
};