class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k)
    {
        int i=0;
        map<int,int>mp;
        int ans=1;
        mp[nums[0]]=1;
        for(int j=1;j<nums.size();j++)
        {
            mp[nums[j]]++;
            while(mp[nums[j]]>k)
            {
                mp[nums[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
        
    }
};