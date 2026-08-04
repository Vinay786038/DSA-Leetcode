class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int>mp(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        if(n==0)
        return 0;
        for(int i:mp)
        {
            int x=1;
            int p=i;
            if(p!=INT_MIN&&mp.count(p-1))
            continue;
            while(p!=INT_MAX&&mp.count(p+1))
            {
                p++;
                x++;
            }
            ans=max(x,ans);
        }
        if(ans==0)
        return 1;
        return ans;
        
    }
};