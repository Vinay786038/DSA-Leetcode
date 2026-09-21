class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k)
    {
        vector<long long>ans(k,0);
        vector<long long>dp(k,0);
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            vector<long long>temp(k,0);
            int mul=nums[i]%k;
            temp[mul]++;
            for(int j=0;j<k;j++)
            {
                if(dp[j])
                {
                    temp[(j*mul)%k]+=dp[j];
                }
            }
            dp=temp;
            for(int j=0;j<k;j++)
            {
                ans[j]+=dp[j];
            }
        }
        return ans;   
    }
};