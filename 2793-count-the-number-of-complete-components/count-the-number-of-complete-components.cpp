class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>>graph(n);
        for(auto &e:edges)
        {
           graph[e[0]].push_back(e[1]);
           graph[e[1]].push_back(e[0]); 
        }
        int ans=0;
       
        vector<int>visi(n,0);
        for(int i=0;i<n;i++)
        {
            if(visi[i]==1)
            {
                continue;
            }
            queue<int>q;
            q.push(i);
            visi[i]=1;
            int degreesum=0;
            int nnode=0;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                nnode++;
                degreesum+=graph[node].size();
                for(int j=0;j<graph[node].size();j++)
                {
                    if(visi[graph[node][j]]==0)
                    {
                        visi[graph[node][j]]=1;
                        q.push(graph[node][j]);
                    }
                }
            }
            int edges=degreesum/2;
            if(edges==(nnode*(nnode-1))/2)
            ans++;
        }
        return ans;
    }
};