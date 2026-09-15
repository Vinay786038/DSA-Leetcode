class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        int n=matches.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int win=matches[i][0];
            int loss=matches[i][1];
            if(mp[win]==0)
            {
                mp[win]=1;
            }
            else
            {
                mp[win]=mp[win];
            }
            if(mp[loss]==-1)
            {
                mp[loss]=10;
            }
            else if(mp[loss]!=10)
            {
                mp[loss]=-1;
            }
        }
        vector<int>ans1;
        vector<int>ans2;
        for(auto x:mp)
        {
            if(x.second==1)
            {
                ans1.push_back(x.first);
            }
            else if(x.second==-1)
            {
                ans2.push_back(x.first);
            }
        }
        vector<vector<int>>ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;

        
    }
};