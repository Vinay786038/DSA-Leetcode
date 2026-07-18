class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n=isConnected.size();
        vector<vector<int>>edges(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1&&i!=j)
                {
                    edges[i].push_back(j);
                }

            }
        }
        int ans=0;
        vector<bool>visi(n,false);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(visi[i])
            {
                continue;
            }
            q.push(i);
            visi[i]=true;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                visi[node]=true;
                for(int j=0;j<edges[node].size();j++)
                {
                    if(visi[edges[node][j]])
                    {
                        continue;
                    }
                    q.push(edges[node][j]);

                }
            }
            ans++;
        }
        return ans;
        
    }
};