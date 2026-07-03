class Solution {
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int ans=0;
        map<char,int>mp1;
        for(int i=0;i<jewels.size();i++)
        {
            if(mp1.find(jewels[i])!=mp1.end())
            {
                mp1[jewels[i]]++;
            }
            else
            {
                mp1[jewels[i]]=1;
            }
        }
        map<char,int>mp2;
        for(int i=0;i<stones.size();i++)
        {
            if(mp2.find(stones[i])!=mp2.end())
            {
                mp2[stones[i]]++;
            }
            else
            {
                mp2[stones[i]]=1;
            }
        }
        for(auto x:mp1)
        {
            int ch=x.first;
            if(mp2.find(ch)!=mp2.end())
            {
                ans+=mp2[ch];
            }
        }
        return ans;
        
    }
};