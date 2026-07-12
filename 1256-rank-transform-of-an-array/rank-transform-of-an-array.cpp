class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr)
    {
        int n=arr.size();
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++)
        {
            p.push_back({arr[i],i});
        }
        sort(p.begin(),p.end());
        vector<int>ans(n);
        int x=1;
        for(int i=0;i<n;i++)
        {
            ans[p[i].second]=x;
            if(i<n-1&&p[i].first==p[i+1].first)
            {
                continue;
            }
            x++;
        }
        return ans;


        
    }
};