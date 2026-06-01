class Solution {
public:
    int minimumCost(vector<int>& cost)
    {
        sort(cost.begin(),cost.end(),greater<int>());
        int res=0;
        int x=0;
        int n=cost.size();
        for(int i=0;i<n;i++)
        {
            res+=cost[i];
            x++;
            if(x==2)
            {
                x=0;
                i++;
            }
        }
        return res;
        
    }
};