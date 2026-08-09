class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<vector<pair<int,int>>>graph(n+1);
        for(int i=0;i<times.size();i++)
        {
            graph[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));
        }
        vector<bool>visi(n+1,false);
        vector<int>wait(n+1,INT_MAX);
        wait[0]=-1;
        wait[k]=0;
        queue<int>q;
        q.push(k);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            visi[node]=true;
            for(int i=0;i<graph[node].size();i++)
            {
                if((wait[graph[node][i].first])>(wait[node]+graph[node][i].second))
                {
                    wait[graph[node][i].first]=wait[node]+graph[node][i].second;
                    q.push(graph[node][i].first);
                }
            }
        }
        for(int i=1;i<n+1;i++)
        {
            if(visi[i]==false)
            return -1;
        }
        int maxx=0;
        for(int i=1;i<n+1;i++)
        {
            maxx=max(maxx,wait[i]);
        }
        return maxx;
        
    }
};