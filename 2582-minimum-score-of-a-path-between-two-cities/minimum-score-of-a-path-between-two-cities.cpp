class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads)
    {
        pair<int,int>p;
        vector<vector<pair<int,int>>>vec(n+1);
        for(int i=0;i<roads.size();i++)
        {
            int a=roads[i][0];
            int b=roads[i][1];
            int c=roads[i][2];
            vec[a].push_back(make_pair(b,c));
            vec[b].push_back(make_pair(a,c));
        }
        vector<bool>visi(n+1,0);
        queue<int>q;
        q.push(1);
        int ans=INT_MAX;
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            visi[top]=1;
            for(int i=0;i<vec[top].size();i++)
            {
                ans=min(ans,vec[top][i].second);
                if(visi[vec[top][i].first]==0)
                {
                    q.push(vec[top][i].first);
                }
            }
        }
        return ans;
        
    }
};