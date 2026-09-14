class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        unordered_map<int,int>mp;
        int maxx=0;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
            maxx=max(maxx,mp[arr[i]]);
        }
        vector<bool>vec(maxx+1,false);
        for(auto x:mp)
        {
            if(vec[x.second]==false)
            {
                vec[x.second]=true;
            }
            else
            return false;
        }
        return true;
    }
};