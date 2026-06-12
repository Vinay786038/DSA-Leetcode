class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>>adj(n);
        for(auto &e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            vector<int>dist(n,-1);
            vector<int>parent(n,-1);
            queue<int>q;
            q.push(i);
            dist[i]=0;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for(int neigh:adj[node])
                {
                    if(dist[neigh]==-1)
                    {
                        dist[neigh]=dist[node]+1;
                        parent[neigh]=node;
                        q.push(neigh);
                    }
                    else if(parent[node]!=neigh)
                    {
                        ans=min(ans,dist[node]+dist[neigh]+1);
                    }
                }
            }
        }
        if(ans==INT_MAX)
        return -1;
        return ans;
    }
};