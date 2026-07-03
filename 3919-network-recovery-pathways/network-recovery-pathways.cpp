class Solution {
public:

    bool check(int score,
               vector<vector<pair<int,int>>>& adj,
               vector<bool>& online,
               long long k)
    {
        int n = adj.size();

        vector<long long> dist(n, LLONG_MAX);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node])
                continue;

            for(auto &[neigh, wt] : adj[node])
            {
                // edge score condition
                if(wt < score)
                    continue;

                // intermediate nodes must be online
                if(neigh != n - 1 && !online[neigh])
                    continue;

                if(dist[node] + wt < dist[neigh])
                {
                    dist[neigh] = dist[node] + wt;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k)
    {
        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);

        int mxEdge = 0;

        for(auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            mxEdge = max(mxEdge, w);
        }

        int low = 0;
        int high = mxEdge;
        int ans = -1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(check(mid, adj, online, k))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};