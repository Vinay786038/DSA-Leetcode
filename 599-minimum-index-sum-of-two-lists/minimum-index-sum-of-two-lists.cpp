class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
    {
        unordered_map<string,int>mp;
        for(int i=0;i<list1.size();i++)
        {
            if(mp.find(list1[i])==mp.end())
            {
                mp[list1[i]]=i;
            }
        }
        unordered_map<string,int>mp1;
        int minn=INT_MAX;
        for(int i=0;i<list2.size();i++)
        {
            if(mp.find(list2[i])!=mp.end())
            {
                if(i+mp[list2[i]]<=minn)
                {
                    mp1[list2[i]]=i+mp[list2[i]];
                    minn=i+mp[list2[i]];
                }
            }
        }
        vector<string>ans;
        for(auto s:mp1)
        {
            if(s.second==minn)
            {
                ans.push_back(s.first);
            }
        }
        return ans;
        
    }
};