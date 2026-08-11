class Solution {
public:
    int missingInteger(vector<int>& nums)
    {
        map<int,int>mp;
        int ans=nums[0];
        int ind=1;
        int n=nums.size();
        if(n==1)
        {
            return nums[0]+1;
        }
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1]+1)
            {
                break;
            }
            ans+=nums[i];
            ind=i;
        }
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=i;
        }
        while(true)
        {
            if(mp.find(ans)==mp.end())
            {
                return ans;
            }
            ans++;
        }
        return -1;


        
    }
};