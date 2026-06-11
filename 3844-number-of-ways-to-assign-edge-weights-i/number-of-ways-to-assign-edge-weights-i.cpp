class Solution {
public:
    const long long MOD=1e9+7;
    long long int power(long long int a,long long int b)
    {
        if(b==1)
        return a;
        if(b==0)
        return 1;
        long long half=power(a,b/2);
        long long ans=(half*half)%MOD;
        if(b&1)
        ans=(ans*a)%MOD;
        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n+1);
        for(auto &e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>visi(n+1,0);
        queue<int>q;
        q.push(1);

        visi[1]=1;
        int depth=-1;
        while(!q.empty())
        {
            int size=q.size();
            depth++;
            while(size>0)
            {
                int node=q.front();
                q.pop();
                for( int &p:adj[node])
                {
                    if(visi[p]==0)
                    {
                        visi[p]=1;
                        q.push(p);
                    }
                }
                size--;
            }
        }
        return power(2,depth-1);
    }
};