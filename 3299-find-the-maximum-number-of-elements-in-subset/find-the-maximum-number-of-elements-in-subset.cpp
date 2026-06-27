class Solution {
public:
    int maximumLength(vector<int>& nums)
    {
        int n=nums.size();
        map<long long,int>mp;
        if(n==0)
        return 0;
        if(n==1||n==2)
        return 1;
        int one=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                one++;
            }
            else
            {
                mp[nums[i]]++;
            }
        }
        if(one!=0&&one%2==0)
        one--;
        int ans=one;
        for(auto& x:mp)
        {
            long long fir=x.first;
            int sec=x.second;
            long long m=sqrt(fir);
            if((m*m==fir)&&mp.count(m)&&mp[m]>1)
            {
                continue;
            }
            int count=0;
            while(mp.count(fir)&&mp[fir]>1)
            {
                count+=2;
                fir=(fir*fir);
            }
            if(mp[fir]==1)
            {
                count++;
            }
            else
            count--;
            ans=max(ans,count);
        }
        return ans;
        
    }
};