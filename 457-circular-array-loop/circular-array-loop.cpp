class Solution {
public:
    bool circularArrayLoop(vector<int>& nums)
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            map<int,int>mp;
            mp[i]=1;
            int j=i;
            bool dir=nums[i]>0;
            while(true)
            {
                if((nums[j]>0)!=dir)
                break;
                int nxt=((j+nums[j])%n+n)%n;
                if(nxt==j)
                break;
                if(mp.find(nxt)!=mp.end())
                {
                    return true;
                }
                mp[nxt]=1;
                j=nxt;
            }

        }
        return false;
        
    }
};