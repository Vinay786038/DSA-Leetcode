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
        for(int i=0;i<stones.size();i++)
        {
            if(mp1.find(stones[i])!=mp1.end())
            {
                ans++;
            }
        }
        return ans;
        
    }
};