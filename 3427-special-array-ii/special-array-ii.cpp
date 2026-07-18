class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
    {
        int n=nums.size();
        vector<int>prefix(n,0);
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1];
            if((nums[i]%2)==(nums[i-1])%2)
            {
                prefix[i]++;
            }
        }
        n=queries.size();
        vector<bool>ans;
        for(int i=0;i<n;i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];
            ans.push_back((prefix[end]-prefix[start])==0);
        }
        return ans;
    }
};