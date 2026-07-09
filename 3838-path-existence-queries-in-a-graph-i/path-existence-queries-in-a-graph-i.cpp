class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) 
    {/*
        int size=queries.size();
        vector<bool>ans(size);
        for(int i=0;i<size;i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];
            if(start>end)
            {
                int temp=start;
                start=end;
                end=temp;
            }
            if(abs(nums[start]-nums[end])<=maxDiff)
            {
                ans[i]=true;
            }
            else
            {
                bool x=true;
                for(int j=start;j<end;j++)
                {
                    if(x&&abs(nums[j]-nums[j+1])>maxDiff)
                    {
                        x=false;
                        break;
                    }
                }
                if(x)
                ans[i]=true;
                else
                ans[i]=false;
            }
        }
        return ans;*/
        vector<int>group(n,0);
        int x=0;
        for(int i=1;i<n;i++)
        {
            if((nums[i]-nums[i-1])>maxDiff)
            x++;
            group[i]=x;
        }
        vector<bool>ans;
        for(auto y:queries)
        {
            int u=y[0];
            int v=y[1];
            ans.push_back(group[u]==group[v]);
        }
        return ans;
    }
};