class Solution {
public:
    int thirdMax(vector<int>& nums)
    {
        vector<int>ans=nums;
        sort(ans.begin(),ans.end(),greater<int>());
        int j=1;
        if(nums.size()<3)
        return ans[0];
        for(int i=0;i<nums.size()-1;i++)
        {
            if(ans[i]==ans[i+1])
            {
                continue;
            }
            j++;
            if(j==3)
            return ans[i+1];
        }
        if(j<3)
        {
            return ans[0];
        }
        return ans[nums.size()-1];
        
    }
};