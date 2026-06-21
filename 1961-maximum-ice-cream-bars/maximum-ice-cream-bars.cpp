class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins)
    {
        int n=costs.size();
        int coin=coins;
        sort(costs.begin(),costs.end());
        if(costs[0]>coin)
        return 0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(costs[i]>coin)
            {
                break;
            }
            coin-=costs[i];
            ans++;
        }
        return ans;
    }
};