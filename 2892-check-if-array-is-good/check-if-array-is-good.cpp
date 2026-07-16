class Solution {
public:
    bool isGood(vector<int>& nums)
    {
        int maxx=nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            maxx=max(maxx,nums[i]);
        }
        if(n!=maxx+1)
        return false;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i==n-2&&nums[i]==maxx)
            continue;
            if(i==n-1&&nums[i]==maxx)
            continue;
            if(i+1!=nums[i])
            return false;
        }
        return true;

        
    }
};