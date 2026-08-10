class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        vector<int>distCount(n);
        vector<vector<pair<int,int>>>graph(n);
        int dd=distanceThreshold;
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
            graph[edges[i][1]].push_back(make_pair(edges[i][0],edges[i][2]));
        }
        for(int i=0;i<n;i++)
        {
            vector<int>dist(n,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            dist[i]=0;
            pq.push({0,i});
            while(!pq.empty())
            {
                int d=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                if(d>dist[node])
                continue;
                for(auto edge:graph[node])
                {
                    int next=edge.first;
                    int wt=edge.second;
                    if(d+wt<dist[next])
                    {
                        dist[next]=d+wt;
                        pq.push({dist[next],next});
                    }
                }
            }
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(j!=i&&dist[j]<=distanceThreshold)
                {
                    count++;
                }
            }
            distCount[i]=count;
        }
        int min=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(distCount[i]<=min)
            {
                min=distCount[i];
                ans=i;
            }
        }
        return ans;
        
    }
};