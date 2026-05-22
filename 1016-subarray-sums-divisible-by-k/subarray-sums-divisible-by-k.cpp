class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        int sub=0;
        map<int,int>mp;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem=((sum%k)+k)%k;
            mp[rem]++;
            if(rem==0)
            sub++;
        
        }
        for(auto s:mp)
        {
            sub+=(s.second*(s.second-1))/2;
        }
        return sub;
     
    }
};