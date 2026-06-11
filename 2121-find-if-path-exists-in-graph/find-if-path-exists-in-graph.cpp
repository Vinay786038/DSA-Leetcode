class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==1)
        return true;
        vector<vector<int>>adj(n);
        for(auto &e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int>q;
        q.push(source);
        vector<bool>visi(n,0);
        visi[source]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++)
            {
                if(adj[node][i]==destination)
                return true;
                if(visi[adj[node][i]]==0)
                {
                    
                    visi[adj[node][i]]=1;
                    q.push(adj[node][i]);
                }
            }
        }
        return false;
        
    }
};