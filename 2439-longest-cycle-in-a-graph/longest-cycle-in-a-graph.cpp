class Solution {
public:
    int longestCycle(vector<int>& edges)
    {
        int ans=-1;
        int n=edges.size();
        vector<bool>visi(n,0);
        for(int i=0;i<n;i++)
        {
            if(visi[i]==1)
            continue;

            unordered_map<int,int>pos;
            int node=i;
            int step=0;
            while(node!=-1&&visi[node]==0)
            {
                visi[node]=1;
                pos[node]=step++;
                node=edges[node];
            }
            if(node!=-1&&pos.count(node))
            {
                ans=max(ans,step-pos[node]);
            }
        }
        return ans;
        

        
     
    }
};