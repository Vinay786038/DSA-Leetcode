class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals)
    {
        int n=intervals.size();
        vector<array<int,4>>a;
        for(int i=0;i<n;i++)
        {
            a.push_back({intervals[i][0],intervals[i][1],intervals[i][2],i});
        }
        sort(a.begin(),a.end());
        vector<int>start(n);
        for(int i=0;i<n;i++)
        {
            start[i]=a[i][0];
        }
        vector<int>next(n);
        for(int i=0;i<n;i++)
        {
            int right=a[i][1];
            next[i]=upper_bound(start.begin(),start.end(),right)-start.begin();
        }
        vector<vector<pair<long long,vector<int>>>>dp(n+1,vector<pair<long long,vector<int>>>(5));
        for(int i=n-1;i>=0;i--)
        {
            for(int k=1;k<=4;k++)
            {
                auto skip=dp[i+1][k];
                auto take=dp[next[i]][k-1];
                take.first+=a[i][2];
                take.second.push_back(a[i][3]);
                sort(take.second.begin(),take.second.end());
                if(take.first>skip.first)
                {
                    dp[i][k]=take;
                }
                else if(take.first<skip.first)
                {
                    dp[i][k]=skip;
                }
                else
                {
                    dp[i][k]=min(take,skip);
                }
            }
        }
        return dp[0][4].second;
    }
};